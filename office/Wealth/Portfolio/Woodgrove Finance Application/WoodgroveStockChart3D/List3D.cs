using System;
using System.IO;
using System.ComponentModel;
using System.Collections;
using System.Collections.Specialized;
using System.Windows.Data;
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
using System.Runtime.InteropServices;
using System.Reflection;
using System.Windows.Resources;

using HitTestResult2D = System.Windows.Media.HitTestResult;
using System.Xml;

namespace WoodgroveFinanceStockChart3D
{
    /// <summary>
    /// Interaction logic for List3D.xaml
    /// </summary>

    #region Public Enums

    public enum List3DItemStates
    {
        Unselected,
        Hover,
        Selected,
        OffScreen,
        OnScreen,
        AnimatingUnselected,
        AnimatingHover,
        AnimatingSelected,
        AnimatingOffScreen,
        AnimatingOnScreen,
    }

    #endregion

    public class List3D : ItemsControl
    {
        // Called Before properties are set
        public List3D()
        {
            ((INotifyCollectionChanged)this.Items).CollectionChanged += new NotifyCollectionChangedEventHandler(OnItemsCollectionChanged);
          
            this.Initialized +=new EventHandler(OnInitialized);
            this.Loaded +=new RoutedEventHandler(OnLoaded);
            this.Background = Brushes.Red;
            
            this.Resources = new Graph3DResources();
        }

        // Called after properties are set
        private void OnInitialized(object sender, EventArgs e)
        {
            // create the basic models
            InitializeModels();

            _List3DItems = new List3DItemCollection(); // init the items collection
        }

        // called after properties are set
        private void OnLoaded(object sender, EventArgs e)
        {
            InitializeViewport3D();

            // MouseInput Handler
            _GridHitTest.PreviewMouseLeftButtonUp += new MouseButtonEventHandler(OnPreviewLeftClick);
            _GridHitTest.PreviewMouseMove += new MouseEventHandler(OnPreviewMouseMove);
            _GridHitTest.Background = new SolidColorBrush(Color.FromArgb(0x01, 0x88, 0x88, 0x88));

            // setup trackball for moving the model around
            _trackball = new Trackball();
            _trackball.Attach(this);
            _trackball.Slaves.Add(_MainViewport3D);
            _trackball.Enabled = true;

            OnLoadedCompleted(null, new EventArgs());
        }

        #region Overrides
        /*
        protected override Size MeasureOverride(Size sizeConstraint)
        {
            //base.MeasureOverride(sizeConstraint);

            //Size sizeMeasured = new Size(0, 0);
            //sizeMeasured.Width = sizeMeasured.Height = Math.Min(sizeConstraint.Width, sizeConstraint.Height);
            return sizeConstraint;
        }

        protected override Size ArrangeOverride(Size sizeArrange)
        {
            return sizeArrange;
        }
         * */
        
        #endregion

        #region Properties

        public List3DItem SelectedItem
        {
            get { return _Selected; }
        }

        Point3D _cameraPosition;
        public Point3D CameraPosition
        {
            get { return _cameraPosition; }
            set { _cameraPosition = value; }
        }

        Vector3D _cameraLookDirection;
        public Vector3D CameraLookDirection
        {
            get { return _cameraLookDirection; }
            set { _cameraLookDirection = value; }
        }

        private string ClientPath
        {
            get
            {
                return System.IO.Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location) + @"\";
            }
        }

        public bool CanHover
        {
            get { return _CanHover; }
            set { _CanHover = value; }
        }

        public bool CanSelect
        {
            get { return _CanSelect; }
            set { _CanSelect = value; }
        }

        public int Columns
        {
            get { return _Columns; }
            set { _Columns = value; }
        }

        public int Rows
        {
            get { return _Rows; }
            set 
            {
                if (value <= 0)
                    return;

                _Rows = value; 
            }
        }

        double _FieldOfView = 40;
        public double FieldOfView
        {
            get { return _FieldOfView; }
            set { _FieldOfView = value; }
        }

        double _HaloXAxisAngle = 0;
        public double HaloXAxisAngle
        {
            get { return _HaloXAxisAngle; }
            set { _HaloXAxisAngle = value; }
        }

        double _HaloZAxisAngle = 0;
        public double HaloZAxisAngle
        {
            get { return _HaloZAxisAngle; }
            set { _HaloZAxisAngle = value; }
        }

        double _HaloYAxisAngle = 0;
        public double HaloYAxisAngle
        {
            get { return _HaloYAxisAngle; }
            set { _HaloYAxisAngle = value; }
        }

        Vector3D _HaloTranslation;
        public Vector3D HaloTranslation
        {
            get { return _HaloTranslation; }
            set { _HaloTranslation = value; }
        }

        Vector3D _HaloScale;
        public Vector3D HaloScale
        {
            get { return _HaloScale; }
            set { _HaloScale = value; }
        }

        Brush _LabelXBrush;
        public Brush LabelXBrush
        {
            get { return _LabelXBrush; }
            set 
            {
                _LabelXBrush = value;
                DiffuseMaterial bm = new DiffuseMaterial(_LabelXBrush);

                // set the texture for the mesh
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_X_TOP]).Material = bm;
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_X_BOTTOM]).Material = bm;
            }
        }

        Brush _LabelZBrush;
        public Brush LabelZBrush
        {
            get { return _LabelZBrush; }
            set
            {
                _LabelZBrush = value;
                DiffuseMaterial bm = new DiffuseMaterial(_LabelZBrush);

                // set the texture for the mesh
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_Z_TOP]).Material = bm;
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_Z_BOTTOM]).Material = bm;
            }
        }

        Brush _LabelValueBrush;
        public Brush LabelValueBrush
        {
            get { return _LabelValueBrush; }
            set
            {
                _LabelValueBrush = value;
                DiffuseMaterial bm = new DiffuseMaterial(_LabelValueBrush);

                // set the texture for the mesh
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_VALUE_TOP]).Material = bm;
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_VALUE_BOTTOM]).Material = bm;
            }
        }

        Brush _LabelSectorBrush;
        public Brush LabelSectorBrush
        {
            get { return _LabelSectorBrush; }
            set
            {
                _LabelSectorBrush = value;
                DiffuseMaterial bm = new DiffuseMaterial(_LabelSectorBrush);

                // set the texture for the mesh
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_SECTOR_TOP]).Material = bm;
                ((GeometryModel3D)_ModelGridItems.Children[_GRIDLABEL_SECTOR_BOTTOM]).Material = bm;
            }
        }

        Brush _DowLabelBrush;
        public Brush DowLabelBrush
        {
            get { return _DowLabelBrush; }
            set
            {
                _DowLabelBrush = value;
                //DiffuseMaterial bm = new DiffuseMaterial(_DowLabelBrush);

                // set the texture for the mesh
                //((GeometryModel3D)_ModelDowGridItems.Children[_DOWGRID_LABEL_BOTTOM]).Material = bm;
            }
        }

        List3DGraphItemStates _List3DState = List3DGraphItemStates.Cube;
        public List3DGraphItemStates List3DState
        {
            get { return _List3DState; }
            set
            {
                _List3DState = value;
            }
        }

        #endregion

        #region Event Handlers

        public delegate void SelectedEventHandler(object sender, EventArgs e);

        public event SelectedEventHandler ItemSelected;
        protected virtual void OnItemSelected(object o, EventArgs e)
        {
            if (ItemSelected != null)
                ItemSelected(o, e);
        }

		public event SelectedEventHandler ItemUnSelected;
		protected virtual void OnItemUnSelected(object o, EventArgs e)
		{
			if (ItemUnSelected != null)
				ItemUnSelected(o, e);
		}

        public event SelectedEventHandler ItemHovered;
        protected virtual void OnItemHovered(object o, EventArgs e)
        {
            if (ItemHovered != null)
                ItemHovered(o, e);
        }

        public event SelectedEventHandler ItemUnHovered;
        protected virtual void OnItemUnHovered(object o, EventArgs e)
        {
            if (ItemUnHovered != null)
                ItemUnHovered(o, e);
        }

        public event SelectedEventHandler LoadedCompleted;
        protected virtual void OnLoadedCompleted(object o, EventArgs e)
        {
            if (LoadedCompleted != null)
                LoadedCompleted(o, e);
        }
        #endregion Event Handlers

        #region Events

        private void OnPreviewLeftClick(object sender, MouseButtonEventArgs e)
        {
            _MainViewport3D.Focus(); // get keyboard focus

            if (CanSelect == false)
                return;

            Point p = e.GetPosition(this);

            DoHitTest(_MainViewport3D, p);

            if (_ciHitTest != null) 
            {
                if (_Selected != _ciHitTest)
                {
                    UnSelectToOnScreen(_Selected);
                    SelectItem(_ciHitTest);
                    _Selected = _ciHitTest;
                    _Hover = null;
                    OnItemSelected(_ciHitTest, new EventArgs());
                }
                else
                {
                    UnSelectToOnScreen(_Selected);
                    _Selected = null;
                    _Hover = null;
                    OnItemUnSelected(_ciHitTest, new EventArgs());

                }
            }

            e.Handled = true;
        }

        private void OnPreviewMouseMove(object sender, MouseEventArgs e)
        {
            if (e.RightButton == MouseButtonState.Pressed)
                return;
            
            Point p = e.GetPosition(this);
            _ciHitTest = null;
            DoHitTest(_MainViewport3D, p);

            if (_ciHitTest != null)
            {
                //if (_ciHitTest == _Selected)
                //    return;

                if (_Hover != _ciHitTest)
                {
                    UnHoverItem(_Hover);
                    HoverItem(_ciHitTest);
                    _Hover = _ciHitTest;
                    OnItemHovered(_Hover, new EventArgs());
                }
            }
            else
            {
                if (_Hover != _Selected)
                {
                    UnHoverItem(_Hover);
                    OnItemUnHovered(_Hover, new EventArgs());
                }
                
                _Hover = null;
            }

            // redraw selected item as hover item may have drawn over it
            if (_Selected != null)
                SelectItem(_Selected);
            
        }

        private void TranslateComplete(object sender, EventArgs e)
        {
            List3DItem item = sender as List3DItem;

            List3DItemStates state = (List3DItemStates)item.Status;

            if (state == List3DItemStates.AnimatingHover)
            {
                item.Status = (int)List3DItemStates.Hover;
            }

            if (state == List3DItemStates.AnimatingUnselected)
            {
                item.Status = (int)List3DItemStates.Unselected;
            }

            if (state == List3DItemStates.AnimatingSelected)
            {
                item.Status = (int)List3DItemStates.Selected;
            }

            if (state == List3DItemStates.AnimatingOffScreen)
            {
                item.Status = (int)List3DItemStates.OffScreen;
            }

            if (state == List3DItemStates.AnimatingOnScreen)
            {
                item.Status = (int)List3DItemStates.Unselected;
            }


        }

        private void OnItemsCollectionChanged(object sender, NotifyCollectionChangedEventArgs args)
        {
            switch (args.Action)
            {
                case NotifyCollectionChangedAction.Add:
                    Add(sender, args);
                    break;

                case NotifyCollectionChangedAction.Remove:
                    Remove(sender, args);
                    break;

                case NotifyCollectionChangedAction.Reset:
                    Reset(sender, args);
                    break;
            }
        }

        #endregion

        #region Public Methods

        public List3DItem FindList3DItem(string id)
        {
           
            List3DItem ciItem = null;
            
            // find the model
            foreach (List3DItem ci in _List3DItems)
            {
                string ciID = XmlGraphHelper.GetID(ci.XmlData);
                if (ciID == id)
                {
                    ciItem = ci;
                    break;
                }
            }
            
            return ciItem;
        }

        public void GraphHistory (int time, XmlDataProvider xml)
        {
            if ((xml == null) || (xml.Document == null))
                return;

            XmlNodeList xnl = xml.Document.GetElementsByTagName("PastDays");

            if (xnl == null)
                return;

            XmlNode xnDays = xnl[0];

            XmlNodeList xnlDays = xnDays.ChildNodes;

            int index = xnlDays.Count - (time+1);

            if (index < 0)
            {
                // reset overlay
                DiffuseMaterial transparent = this.FindResource("TransparentBrush") as DiffuseMaterial;
                foreach (List3DItem li in _List3DItems)
                {
                    li.SetHeight(0, List3DGraphItemStates.CubeOverlay);
                    li.SetMaterial(transparent, List3DGraphItemStates.CubeOverlay);
                }

                // quick hack - grid is off at 1000
                if (_tt3dDowGrid.OffsetY < 1000)
                    GraphDowHistory(time, xml);

                return; 
            }

            XmlNode xnlDay = xnlDays[index];
            XmlNodeList xnlDayItems = xnlDay.ChildNodes;

            MaterialGroup negative = this.FindResource("GraphCubeOverlayBrushNegative") as MaterialGroup;
            MaterialGroup positive = this.FindResource("GraphCubeOverlayBrushPositive") as MaterialGroup; 
            foreach (XmlElement xe in xnlDayItems)
            {
                MaterialGroup dm;
                string id = XmlGraphHelper.GetID(xe);
                double height = XmlGraphHelper.GetHeight(xe);

                List3DItem li = FindList3DItem(id);

                if (li == null)
                    continue;

                li.SetHeight(height, List3DGraphItemStates.CubeOverlay);

                if (height < 0)
                    dm = negative ;
                else
                    dm = positive;

                li.SetMaterial(dm, List3DGraphItemStates.CubeOverlay);
            }

            // quick hack - grid is off at 1000
            if (_tt3dDowGrid.OffsetY < 1000)
                GraphDowHistory(time, xml);

        }

        public void GraphDowHistory(int time, XmlDataProvider xml)
        {
            if ((xml == null) || (xml.Document == null))
                return;

            if (time == -1)
            {
                Vector3D v = new Vector3D();
                v.X = _tt3dDowGrid.OffsetX;
                v.Y = 1000;
                v.Z = _tt3dDowGrid.OffsetZ;
                TranslateModel(_tt3dDowGrid, v);
                return;
            }

            XmlNodeList xnl = xml.Document.GetElementsByTagName("Dow");

            if (xnl == null)
                return;

            XmlNode xnDays = xnl[0];
            XmlNodeList xnlDays = xnDays.ChildNodes;
            int index = xnlDays.Count - (time + 1);

            if (time < xnlDays.Count)
            {
                XmlNode xn = xnlDays[index];

                Vector3D v = new Vector3D();
                v.X = _tt3dDowGrid.OffsetX;
                v.Y = Convert.ToDouble(xn.InnerText);
                v.Z = _tt3dDowGrid.OffsetZ;
                TranslateModel(_tt3dDowGrid, v);
            }

        }

        public void GraphReset()
        {
            Material transparent = new DiffuseMaterial(Brushes.Transparent);

            _tt3dDowGrid.OffsetY = 1000;

            foreach (List3DItem li in _List3DItems)
            {
                li.SetHeight(0, List3DGraphItemStates.Cube);
                li.SetHeight(0, List3DGraphItemStates.CubeOverlay);
                li.SetHeight(0, List3DGraphItemStates.Cylinder);
                li.SetMaterial(transparent, List3DGraphItemStates.Cube);
                li.SetMaterial(transparent, List3DGraphItemStates.CubeOverlay);
                li.SetMaterial(transparent, List3DGraphItemStates.Cylinder);
            }

            // create crosshair
            Material dmTile = this.FindResource("GraphTileBrush") as Material;
            SetCrossHair(_Selected, dmTile);
        }

        public void SelectItem(string ID)
        {
            List3DItem l3di = FindList3DItem(ID);

            if (l3di == null)
                return;

            UnSelectToOnScreen(_Selected);
            SelectItem(l3di);
            _Selected = l3di;
            //OnItemSelected(l3di, new EventArgs());

        }

        public void HoverItem(string ID)
        {
            List3DItem l3di = FindList3DItem(ID);

            if (l3di == null)
                return;

            if (l3di == _Selected)
                return;

            if (_Hover != _Selected)
                UnHoverItem(_Hover);

            HoverItem(l3di);
            _Hover = l3di;

            // redraw selected item as hover item may have drawn over it
            if (_Selected != null)
                SelectItem(_Selected);

        }

        public void ResetTrackball()
        {
            _trackball.Reset();
        }
        #endregion

        #region Private Methods

        public void RotateModelAxisX()
        {
            Transform3DGroup t3dg = _ModelMainItems.Transform as Transform3DGroup;
            RotateTransform3D _GroupRotateTransform = t3dg.Children[2] as RotateTransform3D;

            // setup new animationusing AnimationClockCollection
            RotateTransform3D rt3D = _GroupRotateTransform;
            AxisAngleRotation3D r3d = rt3D.Rotation as AxisAngleRotation3D;

            DoubleAnimation qaCopy = new DoubleAnimation();
            qaCopy.To = 10;
            qaCopy.RepeatBehavior = RepeatBehavior.Forever;
            qaCopy.AutoReverse = true;
            qaCopy.Duration = new TimeSpan(0, 0, 0, 0, 10000);
            qaCopy.Freeze();
            AnimationClock ac = (AnimationClock)qaCopy.CreateClock();
            r3d.ApplyAnimationClock(AxisAngleRotation3D.AngleProperty, ac, HandoffBehavior.SnapshotAndReplace);

        }

        #region HitTesting

        public bool DoHitTest(Visual target, Point p)
        {
            _ModelHitTest = null;

            //loop through all the hits
            VisualTreeHelper.HitTest(target, null, new HitTestResultCallback(HTResult), new PointHitTestParameters(p));

            // You can also target a Visual3D rather than the entire viewport3D
            // VisualOperations.HitTest(Visual3D, null, new HitTestResultDelegate(HTResult), new RayHitTestParameters(origin - like the camera, direction - could be directional vector based on camera position and lookat point));

            // returns closest hit
            //HitTestResult result = VisualTreeHelper.HitTest(target, p);
            //RayHitTestResult ray = result as RayHitTestResult;
            //_ModelHitTest = ray.ModelHit;

            if (_ModelHitTest == null)
                return false;

            _ciHitTest = FindList3DItemPositionFromGeometry(_ModelHitTest);

            if (_ciHitTest == null)
                return false;

            return true;
        }

        
        public HitTestResultBehavior HTResult(HitTestResult result)
        {
            RayHitTestResult ray = result as RayHitTestResult;

            if (ray == null)
                return HitTestResultBehavior.Continue;

            _ciHitTest = FindList3DItemPositionFromGeometry(ray.ModelHit);
            if (_ciHitTest == null)
                return HitTestResultBehavior.Continue;

            if (_ModelHitTest == null)
            {
                _HitTestDistance = ray.DistanceToRayOrigin;
                _ModelHitTest = ray.ModelHit;
            }
            else
            {
                if (ray.DistanceToRayOrigin < _HitTestDistance)
                    _ModelHitTest = ray.ModelHit;
            }

            return HitTestResultBehavior.Continue;
        }
        
        private List3DItem FindList3DItemPositionFromGeometry(Model3D model)
        {
            List3DItem retList3DItem = null;

            if (model == null)
                return retList3DItem;

            foreach (List3DItem li in _List3DItems)
            {
                if (li.XmlData == null)
                    continue;

                if (li.GetHeight(List3DState) == 0)
                    continue;

                if (li.ItemGroup.Children.Count == 1)
                    continue;

                int i = 0;
                foreach (GeometryModel3D gm3d in li.ItemGroup.Children)
                {
                    // BUGBUG - getting around hittest bug - tile geometry is somehow closer
                    if (i == _GEOMETRY_GRAPHTILE)
                    {
                        i++;
                        continue;
                    }

                    if (model == gm3d)
                    {
                        retList3DItem = li;
                        break;
                    }
                    i++;
                }
            }    

            return retList3DItem;
        }

        #endregion

        #region ItemsCollection Methods
     
        private void Reset(object sender, NotifyCollectionChangedEventArgs args)
        {
            if ((sender == null) || (_List3DItems == null) || (_List3DItems.Count != (_GRID_COLUMNS*_GRID_ROWS)) || (_ModelGraphItems == null))
                return;

            UpdateGraphHeight();
        }

        private void Remove(object sender, NotifyCollectionChangedEventArgs args)
        {
			if (args == null) 
				return;
            /*
            object o = args.ChangedItems[0] as object;

            if (o == null)
                return;
             */
        }

        private void Add(object sender, NotifyCollectionChangedEventArgs args)
        {

            if ((args.NewItems == null) || (args.NewItems.Count == 0))
                return;
        }

        #endregion ItemsCollection Methods

        private FrameworkElement FindViewport3D(Visual parent)
        {
            int count = VisualTreeHelper.GetChildrenCount(parent);
            for (int i = 0; i < count; i++)
            {
                Visual visual = VisualTreeHelper.GetChild(parent, i) as Visual;

                if ((visual is FrameworkElement) && (visual is Viewport3D))
                    return (visual as FrameworkElement);
                else
                {
                    FrameworkElement result = FindViewport3D(visual);
                    if (result != null)
                        return result;
                }
            }

            return null;
        }

        private FrameworkElement FindGridParent(Visual parent)
        {
            int count = VisualTreeHelper.GetChildrenCount(parent);
            for (int i = 0; i < count; i++)
            {
                Visual visual = VisualTreeHelper.GetChild(parent, i) as Visual;

                if ((visual is FrameworkElement) && (visual is Grid))
                    return (visual as FrameworkElement);
                else
                {
                    FrameworkElement result = FindViewport3D(visual);
                    if (result != null)
                        return result;
                }
            }

            return null;
        }

        private void HoverItem(List3DItem hover)
        {
            if (hover == null)
                return;

            double height = XmlGraphHelper.GetHeight(hover.XmlData);

            Material dm;
            if (height > 0)
                dm = this.FindResource("HoverGraphCubeBrushPositive") as Material;
            else
                dm = this.FindResource("HoverGraphCubeBrushNegative") as Material;
            hover.SetMaterial(dm, List3DState);

            // create crosshair
            SetCrossHair(hover, dm);
        }

        private void UnHoverItem(List3DItem hover)
        {
            if (hover == null)
                return;

            double height = XmlGraphHelper.GetHeight(hover.XmlData);

            Material dm;
            if (height > 0)
                dm = this.FindResource("GraphCubeBrushPositive") as Material;
            else
                dm = this.FindResource("GraphCubeBrushNegative") as Material;
            hover.SetMaterial(dm, List3DState);

            // create crosshair
            Material dmTile = this.FindResource("GraphTileBrush") as Material;
            SetCrossHair(hover, dmTile);
        }

        private void SelectItem(List3DItem select)
        {
            if (select == null)
                return;

            double height = XmlGraphHelper.GetHeight(select.XmlData);

            Material dm;
            if (height > 0)
                dm = this.FindResource("SelectGraphCubeBrushPositive") as Material;
            else
                dm = this.FindResource("SelectGraphCubeBrushNegative") as Material;
            select.SetMaterial(dm, List3DState);

            // create crosshair
            SetCrossHair(select, dm);
        }

        private void UnSelectToOnScreen(List3DItem select)
        {
            if (select == null)
                return;

            double height = XmlGraphHelper.GetHeight(select.XmlData);

            Material dm;
            if (height > 0)
                dm = this.FindResource("GraphCubeBrushPositive") as Material;
            else
                dm = this.FindResource("GraphCubeBrushNegative") as Material;
            select.SetMaterial(dm, List3DState);

            // create crosshair
            Material dmTile = this.FindResource("GraphTileBrush") as Material;
            SetCrossHair(select, dmTile);
        }

        private void SetCrossHair(List3DItem select, Material dm)
        {
            if ((select == null) || (dm == null))
                return;

            // create crosshair
            int row = XmlGraphHelper.GetRow(select.XmlData);
            int column = XmlGraphHelper.GetColumn(select.XmlData);

            int start = (row * _GRID_COLUMNS);
            for (int i = 0; i < _GRID_ROWS; i++)
            {
                List3DItem li = _List3DItems[start];
                li.SetMaterial(dm, List3DGraphItemStates.Tile);
                start++;
            }

            start = column;
            for (int i = 0; i < _GRID_ROWS; i++)
            {
                List3DItem li = _List3DItems[start];
                li.SetMaterial(dm, List3DGraphItemStates.Tile);
                start += _GRID_COLUMNS;
            }
        }
        /*
        private void HoverItem(List3DItem hover)
        {
            
            Vector3D current, next;

            if ((hover.Status == (int)List3DItemStates.AnimatingOffScreen) || (hover.Status == (int)List3DItemStates.OffScreen) ||
                (hover.Status == (int)List3DItemStates.AnimatingOnScreen))
            {
                return;
            }

            // find the model
            foreach (List3DItem item in _List3DItems)
            {
                if (hover == item)
                    continue;

                List3DItemStates state = (List3DItemStates)item.Status;

                switch (state)
                {
                    case List3DItemStates.AnimatingHover:
                    case List3DItemStates.Hover:
                        current = item.Offset;
                        next = new Vector3D(current.X, current.Y, current.Z);
                        next.Z = 0;

                        item.AnimateTranslate(next);
                        item.Status = (int)List3DItemStates.AnimatingUnselected;
                        break;
                    default:
                        continue;
                        break;

                } // end switch
            } // end foreach

            // hover the item
            if ((hover.Status == (int)List3DItemStates.Selected) || (hover.Status == (int)List3DItemStates.AnimatingSelected))
            {
                _Hover = null;
            }
            else
            {
                current = hover.Offset;
                next = new Vector3D(current.X, current.Y, current.Z);
                next.Z = 1;

                hover.Status = (int)List3DItemStates.AnimatingHover;
                _Hover = hover;
                hover.AnimateTranslate(next);

                string sound = ClientPath + "hover.wav";
              //  PlaySound(sound, 0, SND_ASYNC | SND_NOWAIT | SND_FILENAME);
            }
             
        }
*/
        private int FindItemIndex(string id)
        {
            int index = -1;
            
            // find the model
            int i = 0;
            foreach (List3DItem ci in _List3DItems)
            {
                string ciID = XmlGraphHelper.GetID(ci.XmlData);
                if (ciID == id)
                {
                    index = i;
                    break;
                }
                i++;
            }
            
            return index;
        }

        private void TranslateModel(TranslateTransform3D model_tt3d, Vector3D translate)
        {
            AnimationClock ac;

            // setup X animation
            DoubleAnimation qaCopyX = new DoubleAnimation();
            qaCopyX.To = translate.X;
            qaCopyX.Duration = new TimeSpan(0, 0, 0, 0, 500);
            qaCopyX.Freeze();
            ac = (AnimationClock)qaCopyX.CreateClock();
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetXProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Y animation
            DoubleAnimation qaCopyY = new DoubleAnimation();
            qaCopyY.To = translate.Y;
            qaCopyY.Duration = new TimeSpan(0, 0, 0, 0, 500);
            qaCopyY.Freeze();
            ac = (AnimationClock)qaCopyY.CreateClock();
            //ac.CurrentStateInvalidated += new EventHandler(OnTranslateEnded);
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetYProperty, ac, HandoffBehavior.SnapshotAndReplace);

            // setup Z animation
            DoubleAnimation qaCopyZ = new DoubleAnimation();
            qaCopyZ.To = translate.Z;
            qaCopyZ.Duration = new TimeSpan(0, 0, 0, 0, 500);
            qaCopyZ.Freeze();
            ac = (AnimationClock)qaCopyZ.CreateClock();
            model_tt3d.ApplyAnimationClock(TranslateTransform3D.OffsetZProperty, ac, HandoffBehavior.SnapshotAndReplace);

        }

        private void InitializeModels()
        {
            // Create camera
            //
            Vector3D cameraUp = new Vector3D(0, 1, 0);
            _MainCamera = new PerspectiveCamera (CameraPosition, CameraLookDirection, cameraUp, /* fieldOfView (degrees) = */ FieldOfView);
            _MainCamera.NearPlaneDistance = 0.25;
            _MainCamera.FarPlaneDistance = 100;

            // create Main Model group - light and transforms for all sub model groups go here
            //
            _MainGroupVisual3D = new ModelVisual3D();
            _MainGroup = new Model3DGroup();

            // Create default Transform collection

            // Add transform collection to the _MainGroup
            ScaleTransform3D GroupScaleTransform = new ScaleTransform3D(new Vector3D(1, 1, 1));
            RotateTransform3D GroupRotateTransform = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 1, 0), 0), new Point3D(0, 0, 0));
            TranslateTransform3D GroupTranslateTransform = new TranslateTransform3D(new Vector3D(0, 0, 0));

            // setup Transform collection
            Transform3DCollection tcollection = new Transform3DCollection();
            tcollection.Add(GroupScaleTransform);
            tcollection.Add(GroupRotateTransform);
            tcollection.Add(GroupTranslateTransform);

            // setup group transform
            Transform3DGroup tGroupDefault = new Transform3DGroup();
            tGroupDefault.Children = tcollection;

            _MainGroupVisual3D.Transform = tGroupDefault;
            _MainGroup.Transform = tGroupDefault.Clone();

            // Create sub model group [0] for the light
            //
            _MV3DLights = new ModelVisual3D();
            _ModelLights = new Model3DGroup();

            //AmbientLight light1 = new AmbientLight(Colors.Black);
            DirectionalLight light2 = new DirectionalLight(Colors.LightGray, new Vector3D(0, -1, 1));
            DirectionalLight light3 = new DirectionalLight(Colors.White, new Vector3D(0, 0.1, -1));
            DirectionalLight light4 = new DirectionalLight(Colors.White, new Vector3D(2, -1, -2));
            _ModelLights.Transform = tGroupDefault.Clone();
            //_ModelLights.Children.Add(light1);
            _ModelLights.Children.Add(light2);
            _ModelLights.Children.Add(light3);
            _ModelLights.Children.Add(light4);
            _MV3DLights.Content = _ModelLights;
            //_MainGroup.Children.Add(_ModelLights);

            // Create sub model group [1] for the list items
            //
            _ModelMainItems = new Model3DGroup();

            ScaleTransform3D ModelItemScaleTransform = new ScaleTransform3D(HaloScale);
            RotateTransform3D ModelItemRotateTransformY = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 1, 0), HaloYAxisAngle), new Point3D(0, 0, 0));
            RotateTransform3D ModelItemRotateTransformX = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(1, 0, 0), HaloXAxisAngle), new Point3D(0, 0, 0));
            RotateTransform3D ModelItemRotateTransformZ = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 0, 1), HaloZAxisAngle), new Point3D(0, 0, 0));
            TranslateTransform3D ModelItemTranslateTransform = new TranslateTransform3D(HaloTranslation);

            Transform3DCollection ModelItemtcollection = new Transform3DCollection();
            ModelItemtcollection.Add(ModelItemScaleTransform);
            ModelItemtcollection.Add(ModelItemRotateTransformY);
            ModelItemtcollection.Add(ModelItemRotateTransformX);
            ModelItemtcollection.Add(ModelItemRotateTransformZ);
            ModelItemtcollection.Add(ModelItemTranslateTransform);

            Transform3DGroup ModelItemt3d = new Transform3DGroup();
            ModelItemt3d.Children = ModelItemtcollection;

            _ModelMainItems.Transform = ModelItemt3d;

            // add Grid items
            _ModelGridItems = this.FindResource("StockGraph3DGrid") as Model3DGroup;
            _ModelGridItems = _ModelGridItems.Clone(); // get unfrozen copy because we are going to manipulate the resource
            //_ModelMainItems.Children.Add(_ModelGridItems);

            // add Graph items
            _ModelGraphItems = new Model3DGroup();
            ModelItemScaleTransform = new ScaleTransform3D(new Vector3D(1, 1, 1));
            ModelItemRotateTransformY = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 1, 0), 0), new Point3D(0, 0, 0));
            ModelItemRotateTransformX = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(1, 0, 0), 0), new Point3D(0, 0, 0));
            ModelItemRotateTransformZ = new RotateTransform3D(new AxisAngleRotation3D(new Vector3D(0, 0, 1), 0), new Point3D(0, 0, 0));
            ModelItemTranslateTransform = new TranslateTransform3D(new Vector3D(0, 0, 0));

            Transform3DCollection ModelGraphItemtcollection = new Transform3DCollection();
            ModelGraphItemtcollection.Add(ModelItemScaleTransform);
            ModelGraphItemtcollection.Add(ModelItemRotateTransformY);
            ModelGraphItemtcollection.Add(ModelItemRotateTransformX);
            ModelGraphItemtcollection.Add(ModelItemRotateTransformZ);
            ModelGraphItemtcollection.Add(ModelItemTranslateTransform);

            Transform3DGroup ModelGraphItemt3d = new Transform3DGroup();
            ModelGraphItemt3d.Children = ModelGraphItemtcollection;

            _ModelGraphItems.Transform = ModelGraphItemt3d;
            //_ModelMainItems.Children.Add(_ModelGraphItems);

            // add Dow Graph item
            _ModelDowGridItems = this.FindResource("DowGraphGrid") as Model3DGroup;
            _ModelDowGridItems = _ModelDowGridItems.Clone(); // get unfrozen copy because we are going to manipulate the resource
            //_ModelMainItems.Children.Add(_ModelDowGridItems);
            //Transform3DGroup t3dgDowGrid = _ModelDowGridItems.Transform as Transform3DGroup;
            //_tt3dDowGrid = t3dgDowGrid.Children[1] as TranslateTransform3D;

            // add main group
            _ModelMainItems.Children.Add(_ModelGraphItems);
            _ModelMainItems.Children.Add(_ModelGridItems);

            _ModelMainItems.Children.Add(_ModelDowGridItems);
            Transform3DGroup t3dgDowGrid = _ModelDowGridItems.Transform as Transform3DGroup;
            _tt3dDowGrid = t3dgDowGrid.Children[1] as TranslateTransform3D;

            _MainGroup.Children.Add(_ModelMainItems);
            _MainGroupVisual3D.Content = _MainGroup;

        }

        private void InitializeViewport3D()
        {
            FrameworkElement f = this as FrameworkElement;

            FrameworkElement viewport3DElement = FindViewport3D(f); // since the Viewport3D is in the style, we need to find it.
            _MainViewport3D = viewport3DElement as Viewport3D;

            Grid parent = _MainViewport3D.Parent as Grid;
            _GridHitTest = parent.Children[1] as Grid;

            if (_MainViewport3D != null)
            {
                _MainViewport3D.Camera = _MainCamera;
                _MainViewport3D.Children.Add(_MainGroupVisual3D);
                _MainViewport3D.Children.Add(_MV3DLights);

                LayoutList3DItems();
                UpdateGraphHeight();
            }

        }

        private void LayoutList3DItems()
        {
            // Layout list items
            for (int i = 0; i < _GRID_ROWS; i++)
            {
                for (int j = 0; j < _GRID_COLUMNS; j++)
                {
                    Model3DGroup m3dItem = this.FindResource("StockItemModel") as Model3DGroup;
                    Vector3D scale = new Vector3D(1, 1, 1);
                    Vector3D translate = new Vector3D(j, 0, i);
                    Vector3D rotate = new Vector3D(0, 0, 0);
                    List3DItem l3di = new List3DItem(scale, translate, rotate, m3dItem);
                    _List3DItems.Add(l3di);

                    _ModelGraphItems.Children.Add(l3di.ItemGroup);
                }
            }
        }

        private void UpdateGraphHeight()
        {
            // reset the graph heights
            foreach (XmlElement xe in this.Items)
            {
                int row = XmlGraphHelper.GetRow(xe);
                int column = XmlGraphHelper.GetColumn(xe);
                double height = XmlGraphHelper.GetHeight(xe);

                // set listitem height
                Material dm;

                if (height < 0)
                    dm = this.FindResource("GraphCubeBrushNegative") as Material;
                else
                    dm = this.FindResource("GraphCubeBrushPositive") as Material;

                int index = (row * _GRID_ROWS) + column;
                List3DItem l3di = _List3DItems[index];

                // add models if needed
                GeometryModel3D gm3dCube = this.FindResource("GraphCubeItem") as GeometryModel3D;
                GeometryModel3D gm3dCubeOverlay = this.FindResource("GraphCubeItemOverlay") as GeometryModel3D;
                GeometryModel3D gm3dCylinder = this.FindResource("GraphCylinderItem") as GeometryModel3D;
                GeometryModel3D gm3dTile = this.FindResource("GraphTileItem") as GeometryModel3D;
                l3di.AddItemGeometry(gm3dCube, gm3dCubeOverlay, gm3dCylinder, gm3dTile);

                l3di.SetMaterial(dm, List3DState);
                l3di.SetHeight(height, List3DState);
                l3di.XmlData = xe;
               
            }

        }

        #endregion

        #region Globals

	    // 3D elements
        Viewport3D _MainViewport3D;
        PerspectiveCamera _MainCamera;
        ModelVisual3D _MainGroupVisual3D;
        ModelVisual3D _MV3DLights;
        Model3DGroup _MainGroup;
        TranslateTransform3D _tt3dDowGrid;

        Model3DGroup _ModelLights;
        Model3DGroup _ModelMainItems;
        Model3DGroup _ModelDowGridItems;
        Model3DGroup _ModelGridItems;
        Model3DGroup _ModelGraphItems;

        private Trackball _trackball;

        // Properties
        bool _CanHover = true;
        bool _CanSelect = true;
        int _Columns = 32;
        int _Rows = 1;

        // List3D items
        List3DItemCollection _List3DItems;

        // 3D hittesting
        Grid _GridHitTest;
        List3DItem _ciHitTest;
        Model3D _ModelHitTest = null;
        double _HitTestDistance = 0;

        //List Item tracking
        List3DItem _Hover=null;
        List3DItem _Selected = null;

        // Const
        const int _GRIDLABEL_Z_TOP = 0;
        const int _GRIDLABEL_Z_BOTTOM = 1;
        const int _GRIDLABEL_X_TOP = 2;
        const int _GRIDLABEL_X_BOTTOM = 3;
        const int _GRIDLABEL_SECTOR_TOP = 4;
        const int _GRIDLABEL_SECTOR_BOTTOM = 5;
        const int _GRIDLABEL_VALUE_TOP = 6;
        const int _GRIDLABEL_VALUE_BOTTOM = 7;

        const int _DOWGRID_LABEL_BOTTOM = 3;
        const int _GRID_ROWS = 9;
        const int _GRID_COLUMNS = 9;
        const int _GEOMETRY_GRAPHTILE = 3;

        

        // Const
        const double _GRAPH_SIZERATIO = 10; // size of the 3D grid in 3D space

        #endregion

    }

    namespace DebugHelp3D
    {
        using System.Runtime.InteropServices;
        using System.Text;
        using System.IO;
        // Trace Syntax:
        //		DebugHelp.Trace.Message(a string);
        //
        // Launch "start DBMon" to see the output
        public class Trace
        {
            [DllImport("kernel32.dll", EntryPoint = "OutputDebugStringW", CharSet = CharSet.Unicode, ExactSpelling = true, CallingConvention = CallingConvention.StdCall)]
            private static extern void OutputDebugString(string msg);

            public static void Message(string msg)
            {
                OutputDebugString(msg + "\n");
            }
        }

        public class FileTest
        {
            private static string filePath = System.Environment.GetEnvironmentVariable("TMP").ToString() + @"\log.txt";

            public static void WriteFile(string input)
            {
                FileInfo logFile = new FileInfo(filePath);

                if (logFile.Exists)
                {
                    if (logFile.Length >= 1000000)
                        File.Delete(filePath);
                }

                FileStream fs = new FileStream(filePath, FileMode.OpenOrCreate, FileAccess.ReadWrite);
                StreamWriter w = new StreamWriter(fs);

                w.BaseStream.Seek(0, SeekOrigin.End);
                w.Write(input);
                w.Flush();
                w.Close();
            }

            public static string ReadFile()
            {
                FileStream fs = new FileStream(filePath, FileMode.OpenOrCreate, FileAccess.ReadWrite);
                StringBuilder output = new StringBuilder();

                output.Length = 0;

                StreamReader r = new StreamReader(fs);

                r.BaseStream.Seek(0, SeekOrigin.Begin);
                while (r.Peek() > -1)
                {
                    output.Append(r.ReadLine() + "\n");
                }

                r.Close();
                return output.ToString();
            }
        }
    }



}