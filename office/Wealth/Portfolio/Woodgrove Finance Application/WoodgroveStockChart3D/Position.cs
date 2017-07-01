#region Using directives

using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Media;
using System.Windows.Media.Media3D;

#endregion

namespace WoodgroveFinanceStockChart3D
{
    public class Position3D
    {
        public Position3D()
        {
            _Translation = new Vector3D();
            _Scale = new Vector3D();
            _RotationAxisX = new Vector3D(1, 0, 0);
            _RotationAxisY = new Vector3D(0, 1, 0);
            _RotationAxisZ = new Vector3D(0, 0, 1);
            _RotationAngle = new Vector3D(0, 0, 0);
        }

        #region Properties

        public Vector3D Translation
        {
            get { return _Translation; }
            set { _Translation = value; }
        }

        public Vector3D Scale
        {
            get { return _Scale; }
            set { _Scale = value; }
        }

        public Vector3D RotationAngle
        {
            get { return _RotationAngle; }
            set { _RotationAngle = value; }
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

        #endregion

        #region Globals
        Vector3D _Translation;
        Vector3D _Scale;
        Vector3D _RotationAngle;
        Vector3D _RotationAxisX;
        Vector3D _RotationAxisY;
        Vector3D _RotationAxisZ;


        #endregion

    }
}
