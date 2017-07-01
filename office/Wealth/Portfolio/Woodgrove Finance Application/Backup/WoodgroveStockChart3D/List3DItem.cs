using System;
using System.IO;
using System.ComponentModel;
using System.Collections;
using System.Windows.Navigation;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Documents;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Media.Media3D;
using System.Windows.Shapes;
using System.Windows.Input;
using System.Threading;
using System.Windows.Markup;
using System.Reflection;
using System.Windows.Resources;
using System.Xml;



namespace WoodgroveFinanceStockChart3D
{
    #region Public Enums

    public enum List3DGraphItemStates
    {
        Cube,
        CubeOverlay,
        Cylinder,
        Tile
    }
    #endregion
    /// <summary>
    /// Interaction logic for Button3D.xaml
    /// </summary>
    public class List3DItem : INotifyPropertyChanged
	{

        // The OnLoaded handler can be run automatically when the class is loaded. To use it, add Loaded="OnLoaded" to the attributes of the root element of the .xaml file and uncomment the following line.

        public List3DItem(Vector3D scale, Vector3D translate, Vector3D rotate, Model3DGroup mainGroup)
        {
            _MainGroup = mainGroup;
            _MainGroup = _MainGroup.Clone(); // get unfrozen copy because we are going to manipulate the resource
            _ItemGroup = _MainGroup;

            // save the original location
            _OriginalGroupScale = scale;
            _OriginalGroupTranslate = translate;
            _OriginalGroupRotate = rotate.Y;

            Transform3DGroup t3dg = _ItemGroup.Transform as Transform3DGroup;

            // save the modelgroup's transforms for 
            _GroupScaleTransform = t3dg.Children[0] as ScaleTransform3D;
            _GroupRotateTransformY = t3dg.Children[1] as RotateTransform3D;
            _GroupRotateTransformX = t3dg.Children[2] as RotateTransform3D;
            _GroupRotateTransformZ = t3dg.Children[3] as RotateTransform3D;
            _GroupTranslateTransform = t3dg.Children[4] as TranslateTransform3D;
            RotationAxisX = new Vector3D(1, 0, 0); // set default rotation axis
            RotationAxisY = new Vector3D(0, 1, 0); // set default rotation axis
            RotationAxisZ = new Vector3D(0, 0, 1); // set default rotation axis
            _GroupScaleTransform.ScaleX = scale.X;
            _GroupScaleTransform.ScaleY = scale.Y;
            _GroupScaleTransform.ScaleZ = scale.Z;
            _GroupTranslateTransform.OffsetX = translate.X;
            _GroupTranslateTransform.OffsetY = translate.Y;
            _GroupTranslateTransform.OffsetZ = translate.Z;
            _GroupRotateTransformX.Rotation = new AxisAngleRotation3D(RotationAxisX, rotate.X);
            _GroupRotateTransformY.Rotation = new AxisAngleRotation3D(RotationAxisY, rotate.Y);
            _GroupRotateTransformZ.Rotation = new AxisAngleRotation3D(RotationAxisZ, rotate.Z);

            // setup the GraphCube globals
            if (_ItemGroup.Children.Count == 1)
                _GraphTileGeometry = _ItemGroup.Children[0] as GeometryModel3D;
		}

		#region Property Changed
		public event PropertyChangedEventHandler PropertyChanged;

		private void NotifyPropertyChanged(string propName)
		{
			if (PropertyChanged != null)
			{
				PropertyChanged(this, new PropertyChangedEventArgs(propName));
			}
		}
		#endregion

		#region Properties

        public Model3DGroup ItemGroup
        {
            get
            {
                return _ItemGroup;
            }
        }

        XmlElement _XmlData=null;
        public XmlElement XmlData
        {
            get { return _XmlData; }
            set { _XmlData = value; }
        }

        private string _StockDate = "date";
        public string StockDate
        {
            get { return _StockDate; }
            set { _StockDate = value; }
        }

        private double _StockPrice = 0;
        public double StockPrice
        {
            get { return _StockPrice; }
            set { _StockPrice = value; }
        }

        public Vector3D Angle
        {
            get
            {
                Vector3D v = new Vector3D();

                RotateTransform3D rt3DX = _GroupRotateTransformX.CloneCurrentValue();
                double angle = 0;

                if (rt3DX.Rotation != null)
                {
                    angle = (rt3DX.Rotation as AxisAngleRotation3D).Angle;
                }
                v.X = angle;

                RotateTransform3D rt3DY = _GroupRotateTransformY.CloneCurrentValue();
                angle = 0;

                if (rt3DY.Rotation != null)
                {
                    angle = (rt3DY.Rotation as AxisAngleRotation3D).Angle;
                }
                v.Y = angle;

                RotateTransform3D rt3DZ = _GroupRotateTransformZ.CloneCurrentValue();
                angle = 0;

                if (rt3DZ.Rotation != null)
                {
                    angle = (rt3DZ.Rotation as AxisAngleRotation3D).Angle;
                }
                v.Z = angle;


                return v;
            }
        }

        public Vector3D Offset
        {
            get
            {
                TranslateTransform3D tt3D = _GroupTranslateTransform.CloneCurrentValue();
                return new Vector3D (tt3D.OffsetX, tt3D.OffsetY,tt3D.OffsetZ);
            }
        }

        public Vector3D Scale
        {
            get
            {
                ScaleTransform3D st3D = _GroupScaleTransform.CloneCurrentValue();
                return new Vector3D (st3D.ScaleX,st3D.ScaleY,st3D.ScaleZ);
            }
        }

        public Vector3D RotationAxisX
        {
            get { return _RotationAxisX; }
            set { _RotationAxisX = value; }
        }

        public Vector3D RotationAxisY
        {
            get { return _RotationAxisY; }
            set { _RotationAxisY = value; }
        }

        public Vector3D RotationAxisZ
        {
            get { return _RotationAxisZ; }
            set { _RotationAxisZ = value; }
        }

        public int Duration
        {
            get { return _Duration; }
            set { _Duration = value; }
        }

        public int Status
        {
            get { return _Status; }
            set { _Status = value; }
        }

        public Position3D  FrontPosition
        {
            get { return _FrontPosition; }
            set { _FrontPosition = value; }
        }

        public Position3D DefaultPosition
        {
            get { return _DefaultPosition; }
            set { _DefaultPosition = value; }
        }

        public Position3D BackPosition
        {
            get { return _BackPosition; }
            set { _BackPosition = value; }
        }

        #endregion Properties

        #region Event Handlers

        public delegate void SelectedEventHandler(object sender, EventArgs e);

        public event SelectedEventHandler TranslateComplete;
        protected virtual void OnTranslateComplete(object o, EventArgs e)
        {
            if (TranslateComplete != null)
                TranslateComplete(o, e);
        }

        #endregion Event Handlers

        #region Events
        #endregion Events

		#region Public Methods

        public void AddItemGeometry(GeometryModel3D gm3dCube, GeometryModel3D gm3dCubeOverlay, GeometryModel3D gm3dCylinder, GeometryModel3D gm3dTile)
        {
            if ((_ItemGroup == null) || (_ItemGroup.Children.Count > 1))
                return;

            _ItemGroup.Children.Clear();
            _ItemGroup.Children.Add(gm3dCube);
            _ItemGroup.Children.Add(gm3dCylinder);
            _ItemGroup.Children.Add(gm3dCubeOverlay);
            _ItemGroup.Children.Add(gm3dTile);

           // setup the GraphCube globals
           _GraphCubeGeometry = _ItemGroup.Children[_GEOMETRY_GRAPHCUBE] as GeometryModel3D;
           Transform3DGroup t3dg = _GraphCubeGeometry.Transform as Transform3DGroup;
           _GraphCubeScaleTransform = t3dg.Children[0] as ScaleTransform3D;
           _GraphCubeTranslateTransform = t3dg.Children[1] as TranslateTransform3D;

           // setup the GraphCube globals
           _GraphCylinderGeometry = _ItemGroup.Children[_GEOMETRY_GRAPHCYLINDER] as GeometryModel3D;
           t3dg = _GraphCylinderGeometry.Transform as Transform3DGroup;
           _GraphCylinderScaleTransform = t3dg.Children[0] as ScaleTransform3D;
           _GraphCylinderTranslateTransform = t3dg.Children[1] as TranslateTransform3D;

           // setup the GraphCube globals
           _GraphCubeOverlayGeometry = _ItemGroup.Children[_GEOMETRY_GRAPHCUBEOVERLAY] as GeometryModel3D;
           t3dg = _GraphCubeOverlayGeometry.Transform as Transform3DGroup;
           _GraphCubeOverlayScaleTransform = t3dg.Children[0] as ScaleTransform3D;
           _GraphCubeOverlayTranslateTransform = t3dg.Children[1] as TranslateTransform3D;

           // setup the GraphCube globals
           _GraphTileGeometry = _ItemGroup.Children[_GEOMETRY_GRAPHTILE] as GeometryModel3D;
           t3dg = _GraphTileGeometry.Transform as Transform3DGroup;
           _GraphTileScaleTransform = t3dg.Children[0] as ScaleTransform3D;
           _GraphTileTranslateTransform = t3dg.Children[1] as TranslateTransform3D;

            
        }

        public void AnimateScale(ScaleTransform3D transform, Vector3D v )
        {
            if (transform == null)
                return;

            if ((transform.ScaleX == v.X) && (transform.ScaleY == v.Y) && (transform.ScaleZ == v.Z))
                return;

            ScaleModel(transform, v);
        }

        public void AnimateTranslate(TranslateTransform3D transform, Vector3D v)
        {
            if (transform == null)
                return;

            if ((transform.OffsetX == v.X) && (transform.OffsetY == v.Y) && (transform.OffsetZ == v.Z))
                return;

            TranslateModel(transform, v);
        }

        public void AnimateRotate(Vector3D angle)
        {
            if (angle == Angle)
                return;

            RotateModel(_GroupRotateTransformX, angle.X);
            RotateModel(_GroupRotateTransformY, angle.Y);
            RotateModel(_GroupRotateTransformZ, angle.Z);
        }

        public void SetRotationX(Vector3D axis, double angle)
        {
            RotateTransform3D rt3D = _GroupRotateTransformX.CloneCurrentValue();

            if (rt3D.Rotation == null)
                rt3D.Rotation = new AxisAngleRotation3D(axis, angle);
            else
            {
                (rt3D.Rotation as AxisAngleRotation3D).Axis = axis;
                (rt3D.Rotation as AxisAngleRotation3D).Angle = angle;
            }
        }

        public void SetRotationY(Vector3D axis, double angle)
        {
            RotateTransform3D rt3D = _GroupRotateTransformY.CloneCurrentValue();

            if (rt3D.Rotation == null)
                rt3D.Rotation = new AxisAngleRotation3D(axis, angle);
            else
            {
                (rt3D.Rotation as AxisAngleRotation3D).Axis = axis;
                (rt3D.Rotation as AxisAngleRotation3D).Angle = angle;
            }
        }

        public void SetRotationZ(Vector3D axis, double angle)
        {
            RotateTransform3D rt3D = _GroupRotateTransformZ.CloneCurrentValue();

            if (rt3D.Rotation == null)
                rt3D.Rotation = new AxisAngleRotation3D(axis, angle);
            else
            {
                (rt3D.Rotation as AxisAngleRotation3D).Axis = axis;
                (rt3D.Rotation as AxisAngleRotation3D).Angle = angle;
            }
        }
        public void SetScale(Vector3D scale)
        {
            if (scale == null)
                return;

            _GroupScaleTransform.ScaleX = scale.X;
            _GroupScaleTransform.ScaleY = scale.Y;
            _GroupScaleTransform.ScaleZ = scale.Z;
        }

        public void SetOffset(Vector3D offset)
        {
            if (offset == null)
                return;

            _GroupTranslateTransform.OffsetX = offset.X;
            _GroupTranslateTransform.OffsetY = offset.Y;
            _GroupTranslateTransform.OffsetZ = offset.Z;
        }

        public void SetMaterial(Material material, List3DGraphItemStates state)
        {

            if (state == List3DGraphItemStates.Tile)
            {
                _GraphTileGeometry.Material = material;
            }

            if ((_ItemGroup == null) || (_ItemGroup.Children.Count <= 1))
                return;

            if (state == List3DGraphItemStates.Cube)
            {
                _GraphCubeGeometry.Material = material;
            }

            if (state == List3DGraphItemStates.CubeOverlay)
            {
                _GraphCubeOverlayGeometry.Material = material;
            }

            if (state == List3DGraphItemStates.Cylinder)
            {
                _GraphCylinderGeometry.Material = material;
            }
        }

        public void SetHeight(double height, List3DGraphItemStates state)
        {
            if ((_ItemGroup == null) || (_ItemGroup.Children.Count <= 1))
                return;

            Vector3D v = new Vector3D();

            if (state == List3DGraphItemStates.Cube)
            {
                //_GraphCubeScaleTransform.ScaleY = height;
                //_GraphCubeTranslateTransform.OffsetY = height / 2;

                v.X = _GraphCubeScaleTransform.ScaleX;
                v.Y = height;
                v.Z = _GraphCubeScaleTransform.ScaleZ;
                AnimateScale(_GraphCubeScaleTransform, v);

                v.X = _GraphCubeTranslateTransform.OffsetX;
                v.Y = height / 2;
                v.Z = _GraphCubeTranslateTransform.OffsetZ;
                AnimateTranslate(_GraphCubeTranslateTransform, v);
            }

            if (state == List3DGraphItemStates.CubeOverlay)
            {
                v.X = _GraphCubeOverlayScaleTransform.ScaleX;
                v.Y = height;
                v.Z = _GraphCubeOverlayScaleTransform.ScaleZ;
                AnimateScale(_GraphCubeOverlayScaleTransform, v);

                v.X = _GraphCubeOverlayTranslateTransform.OffsetX;
                v.Y = height / 2;
                v.Z = _GraphCubeOverlayTranslateTransform.OffsetZ;
                AnimateTranslate(_GraphCubeOverlayTranslateTransform, v);
            }

            if (state == List3DGraphItemStates.Cylinder)
            {
                //_GraphCylinderScaleTransform.ScaleY = height;
                //_GraphCylinderTranslateTransform.OffsetY = height / 2;

                v.X = _GraphCylinderScaleTransform.ScaleX;
                v.Y = height;
                v.Z = _GraphCylinderScaleTransform.ScaleZ;
                AnimateScale(_GraphCylinderScaleTransform, v);

                v.X = _GraphCylinderTranslateTransform.OffsetX;
                v.Y = height / 2.025;
                v.Z = _GraphCylinderTranslateTransform.OffsetZ;
                AnimateTranslate(_GraphCylinderTranslateTransform, v);
            }
        }

        public double GetHeight(List3DGraphItemStates state)
        {
            if ((_ItemGroup == null) || (_ItemGroup.Children.Count <= 1))
                return 0;


            if (state == List3DGraphItemStates.Cube)
            {
                return _GraphCubeScaleTransform.ScaleY;
            }

            if (state == List3DGraphItemStates.CubeOverlay)
            {
                return _GraphCubeOverlayScaleTransform.ScaleY;
            }

            if (state == List3DGraphItemStates.Cylinder)
            {
                return _GraphCylinderScaleTransform.ScaleY;
            }

            return 0;
        }

        public void AnimatePostion(Position3D p)
        {
            /*
            AnimateScale(p.Scale);
            AnimateTranslate(p.Translation);
            RotationAxisX = p.RotationAxisX;
            RotationAxisY = p.RotationAxisY;
            RotationAxisZ = p.RotationAxisZ;
            AnimateRotate(p.RotationAngle);
             */
        }

        public void SetPosition(Position3D p)
        {
            SetScale(p.Scale);
            SetOffset(p.Translation);
            SetRotationX(p.RotationAxisX, p.RotationAngle.X);
            SetRotationY(p.RotationAxisY, p.RotationAngle.Y);
            SetRotationZ(p.RotationAxisZ, p.RotationAngle.Z);
        }

        public void Rotate(double angle)
        {
            /*
            PropertyAnimationClockCollection acc = _GroupRotateTransformY.GetAnimationClocks(RotateTransform3D.RotationProperty);
            AnimationClock ac = null;

            if (acc.Count > 0)
                ac = acc[0] as AnimationClock;
            
            if ((ac != null) && (ac.IsPaused == true))
            {
                ac.ClockController.Resume();
            }
            else
            {
                _rotateForeverTracking = 90;
                _OriginalGroupRotate = angle;
                RotateModelForever(_GroupRotateTransformY, angle, angle + _rotateForeverTracking, Duration);
            }
             */
        }

        public void StopRotate()
        {
            /*
            PropertyAnimationClockCollection acc = _GroupRotateTransformY.GetAnimationClocks(RotateTransform3D.RotationProperty);
            AnimationClock ac = acc[0];
            ac.ClockController.Pause();
             */
        }

        public void RockerModel ()
        {
            RockModel(_GroupRotateTransformY);
        }

		#endregion Public Methods

        #region Private Methods

        #region Animations

        private void RotateModel(RotateTransform3D model_rt3d, double rotate)
        {
            // setup new animationusing AnimationClockCollection
            RotateTransform3D rt3D = model_rt3d;
            AxisAngleRotation3D r3d = rt3D.Rotation as AxisAngleRotation3D;

            DoubleAnimation qaCopy = new DoubleAnimation();

            double angle = 0;
            if (rt3D.Rotation != null)
                angle = (rt3D.Rotation as AxisAngleRotation3D).Angle;

            //qaCopy.From = angle;
            qaCopy.To = rotate;

            //qaCopy.FillBehavior = FillBehavior.HoldEnd;
            qaCopy.AccelerationRatio = 0.5;
            qaCopy.DecelerationRatio = 0.5;
            qaCopy.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            //qaCopy.BeginTime = TimeManager.CurrentGlobalTime;

            qaCopy.Freeze();
            AnimationClock ac = (AnimationClock)qaCopy.CreateClock();
            ac.CurrentStateInvalidated += new EventHandler(OnRotateEnded);
            r3d.ApplyAnimationClock(AxisAngleRotation3D.AngleProperty, ac, HandoffBehavior.SnapshotAndReplace);
        }


        private void RotateModelForever(RotateTransform3D model_rt3d, double start, double end, int duration)
        {

            // setup new animationusing AnimationClockCollection
            RotateTransform3D rt3D = model_rt3d;
            AxisAngleRotation3D r3d = rt3D.Rotation as AxisAngleRotation3D;

            DoubleAnimation qaCopy = new DoubleAnimation();

            double angle = 0;
            if (rt3D.Rotation != null)
                angle = (rt3D.Rotation as AxisAngleRotation3D).Angle;

            //qaCopy.From = start;
            qaCopy.To = start + 90;

            //qaCopy.RepeatBehavior = RepeatBehavior.Forever;
            //qaCopy.IsCumulative = true;
            //qaCopy.FillBehavior = FillBehavior.HoldEnd;
            //qaCopy.AccelerationRatio = 0.5;
            //qaCopy.DecelerationRatio = 0.5;
            qaCopy.Duration = new TimeSpan(0, 0, 0, 0, duration);
            //qaCopy.BeginTime = TimeManager.CurrentGlobalTime;
            qaCopy.Freeze();
            AnimationClock ac = (AnimationClock)qaCopy.CreateClock();
            ac.CurrentStateInvalidated += new EventHandler(OnRotateForeverEnded);
            r3d.ApplyAnimationClock(AxisAngleRotation3D.AngleProperty, ac, HandoffBehavior.SnapshotAndReplace);
        }

        private void RockModel(RotateTransform3D model_rt3d)
        {

            RotateTransform3D rt3D = model_rt3d;
            AxisAngleRotation3D r3d = rt3D.Rotation as AxisAngleRotation3D;


            DoubleAnimation qaCopy = new DoubleAnimation();

            double angle = 0;
            if (rt3D.Rotation != null)
                angle = (rt3D.Rotation as AxisAngleRotation3D).Angle;

            //qaCopy.From = angle;
            qaCopy.To = 10;

            //qaCopy.FillBehavior = FillBehavior.HoldEnd;
            qaCopy.AccelerationRatio = 0.5;
            qaCopy.DecelerationRatio = 0.5;
            qaCopy.RepeatBehavior = RepeatBehavior.Forever;
            qaCopy.AutoReverse = true;
            qaCopy.Duration = new TimeSpan(0, 0, 0, 0, 3000);
            //qaCopy.BeginTime = TimeManager.CurrentGlobalTime;
            qaCopy.Freeze();
            AnimationClock ac = (AnimationClock)qaCopy.CreateClock();
            r3d.ApplyAnimationClock(AxisAngleRotation3D.AngleProperty, ac, HandoffBehavior.SnapshotAndReplace);

        }

        private void TranslateModel(TranslateTransform3D model_tt3d, Vector3D translate)
        {
            AnimationClock ac;

            // setup X animation
            DoubleAnimation qaCopyX = new DoubleAnimation();
            qaCopyX.To = translate.X;
            qaCopyX.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyX.Freeze();
            ac = (AnimationClock)qaCopyX.CreateClock();
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetXProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Y animation
            DoubleAnimation qaCopyY = new DoubleAnimation();
            qaCopyY.To = translate.Y;
            qaCopyY.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyY.Freeze();
            ac = (AnimationClock)qaCopyY.CreateClock();
            //ac.CurrentStateInvalidated += new EventHandler(OnTranslateEnded);
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetYProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Z animation
            DoubleAnimation qaCopyZ = new DoubleAnimation();
            qaCopyZ.To = translate.Z;
            qaCopyZ.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyZ.Freeze();
            ac = (AnimationClock)qaCopyZ.CreateClock();
            ac.CurrentStateInvalidated += new EventHandler(OnTranslateEnded);
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetZProperty, ac, HandoffBehavior.SnapshotAndReplace);

        }

        private void ScaleModel(ScaleTransform3D model_st3d, Vector3D scale)
        {
            AnimationClock ac;

            // setup X animation
            DoubleAnimation qaCopyX = new DoubleAnimation();
            qaCopyX.To = scale.X;
            qaCopyX.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyX.Freeze();
            ac = (AnimationClock)qaCopyX.CreateClock();
            ac.CurrentStateInvalidated += new EventHandler(OnScaleEnded);
            model_st3d.ApplyAnimationClock(ScaleTransform3D.ScaleXProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Y animation
            DoubleAnimation qaCopyY = new DoubleAnimation();
            qaCopyY.To = scale.Y;
            qaCopyY.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyY.Freeze();
            ac = (AnimationClock)qaCopyY.CreateClock();
            model_st3d.ApplyAnimationClock(ScaleTransform3D.ScaleYProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Z animation
            DoubleAnimation qaCopyZ = new DoubleAnimation();
            qaCopyZ.To = scale.Z;
            qaCopyZ.Duration = new TimeSpan(0, 0, 0, 0, Duration);
            qaCopyZ.Freeze();
            ac = (AnimationClock)qaCopyZ.CreateClock();
            model_st3d.ApplyAnimationClock(ScaleTransform3D.ScaleZProperty, ac, HandoffBehavior.SnapshotAndReplace);

        }
        private void OnRotateEnded(object sender, EventArgs args)
        {   /*
            if (sender == null)
                return;

            Clock clock = sender as Clock;

            if (clock == null)
                return;

            if (clock.CurrentState == ClockState.Filling)
            {
             * // put event handler here
            }
            */
        }

        private void OnTranslateEnded(object sender, EventArgs args)
        {
            if (sender == null)
                return;

            Clock clock = sender as Clock;

            if (clock == null)
                return;

            if (clock.CurrentState == ClockState.Filling)
            {
                OnTranslateComplete(this, new EventArgs());
            }
        }

        private void OnScaleEnded(object sender, EventArgs args)
        {
            /*
            if (sender == null)
                return;

            Clock clock = sender as Clock;

            if (clock == null)
                return;

            if (clock.CurrentState == ClockState.Filling)
            {
                // put event handler here
            }
            */
        }

        private void OnRotateForeverEnded(object sender, EventArgs args)
        {
            if (sender == null)
                return;

            Clock clock = sender as Clock;

            if (clock == null)
                return;

            if (clock.CurrentState == ClockState.Filling)
            {

                double start = _OriginalGroupRotate + _rotateForeverTracking;
                double end = start + 90;
                _rotateForeverTracking += 90;

                if (_rotateForeverTracking == 90)
                    RotateModelForever(_GroupRotateTransformY, start + 1, end, Duration);

                if ((_rotateForeverTracking == 180) || (_rotateForeverTracking == 270))
                    RotateModelForever(_GroupRotateTransformY, start, end, Duration);

                if (_rotateForeverTracking == 360)
                {
                    RotateModelForever(_GroupRotateTransformY, start, end - 1, Duration);
                    _rotateForeverTracking = 0;
                }
            }
        }
        

        #endregion Animations

	    #endregion Private Methods

        #region Globals

        // 3D vars
        Model3DGroup _MainGroup;
        Model3DGroup _ItemGroup;

        ScaleTransform3D _GroupScaleTransform;
        TranslateTransform3D _GroupTranslateTransform;
        RotateTransform3D _GroupRotateTransformX;
        RotateTransform3D _GroupRotateTransformY;
        RotateTransform3D _GroupRotateTransformZ;

        GeometryModel3D _GraphCubeGeometry;
        ScaleTransform3D _GraphCubeScaleTransform;
        TranslateTransform3D _GraphCubeTranslateTransform;

        GeometryModel3D _GraphCubeOverlayGeometry;
        ScaleTransform3D _GraphCubeOverlayScaleTransform;
        TranslateTransform3D _GraphCubeOverlayTranslateTransform;

        GeometryModel3D _GraphCylinderGeometry;
        ScaleTransform3D _GraphCylinderScaleTransform;
        TranslateTransform3D _GraphCylinderTranslateTransform;

        GeometryModel3D _GraphTileGeometry;
        ScaleTransform3D _GraphTileScaleTransform;
        TranslateTransform3D _GraphTileTranslateTransform;



        Vector3D _OriginalGroupScale;
        Vector3D _OriginalGroupTranslate;
        double   _OriginalGroupRotate;

        // Properties
        Brush _MainImage;
        Brush _BackImage;
        int _Status = 0;
        Vector3D _RotationAxisX;
        Vector3D _RotationAxisY;
        Vector3D _RotationAxisZ;
        int _Duration = 300;
        Position3D _FrontPosition;
        Position3D _DefaultPosition;
        Position3D _BackPosition;

        // animation tracking
        int _rotateForeverTracking = 0;

        // Video Widget
        Model3DGroup _VideoGroup;
        Position3D _VideoStartPosition3D;
        Position3D _VideoEndPosition3D;

		//consts
        private const int MAIN_IMAGE_INDEX = 0; // mesh location for main image
        private const int _GEOMETRY_GRAPHTILE = 3;
        private const int _GEOMETRY_GRAPHCUBE = 0;
        private const int _GEOMETRY_GRAPHCYLINDER = 1;
        private const int _GEOMETRY_GRAPHCUBEOVERLAY = 2;

        #endregion Globals

    }
    
}