using System;
using System.IO;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Animation;
using System.Windows.Navigation;
using System.Windows.Input;
using System.Globalization;
using System.Collections.Generic;
using System.Text;
using System.Xml;
using WoodgroveFinanceStockChart3D;

namespace WoodgroveFinanceStockChartFrame
{
    public class StockListBox : ListBox
    {
        protected override DependencyObject GetContainerForItemOverride()
        {
            StockListBoxItem slbi = new StockListBoxItem();
            slbi.MouseEnter += new MouseEventHandler(ItemMouseEnter);
            this.LayoutUpdated += new EventHandler(StockListBox_LayoutUpdated);
            
            return slbi;
        }

        void StockListBox_LayoutUpdated(object sender, EventArgs e)
        {
            // select the hover state
            for (int i = 0; i < this.Items.Count; i++)
            {
                XmlElement xe = this.Items[i] as XmlElement;
                if (xe == null)
                    return;

                DependencyObject dob = this.ItemContainerGenerator.ContainerFromIndex(i);
                StockListBoxItem slbi = dob as StockListBoxItem;

                int mod = i % 2;
                if (mod == 0)
                    slbi.SetValue(StockListBoxItem.IsEvenProperty, true);
                else
                    slbi.SetValue(StockListBoxItem.IsEvenProperty, false);
            }
        }

        public delegate void HilightedEventHandler(object sender, EventArgs e);
        public event HilightedEventHandler ItemHilight;
        protected virtual void OnHilightSelected(object o, EventArgs e)
        {
            if (ItemHilight != null)
                ItemHilight(o, e);
        }

        void ItemMouseEnter(object sender, MouseEventArgs e)
        {
            if (sender == null)
                return;

            OnHilightSelected(sender, new EventArgs());
        }
    }

    public class StockListBoxItem : ListBoxItem
    {
        #region Dependency Properties IsItemSelected

        public static readonly DependencyProperty IsItemSelectedProperty = DependencyProperty.RegisterAttached("IsItemSelected",
            typeof(bool), typeof(StockListBoxItem), new FrameworkPropertyMetadata(false, new PropertyChangedCallback(IsItemSelectedInvalidated)));

        public static bool GetIsItemSelected(DependencyObject d)
        {
            return (bool)(d.GetValue(StockListBoxItem.IsItemSelectedProperty));
        }

        public static void SetIsItemSelected(DependencyObject d, bool value)
        {
            d.SetValue(StockListBoxItem.IsItemSelectedProperty, value);
        }

        private static void IsItemSelectedInvalidated(DependencyObject target, DependencyPropertyChangedEventArgs e)
        {
            if (target == null)
                return;
        }
        #endregion

        #region Dependency Properties IsMouseHoverSelected

        public static readonly DependencyProperty IsMouseHoverSelectedProperty = DependencyProperty.RegisterAttached("IsMouseHoverSelected",
            typeof(bool), typeof(StockListBoxItem), new FrameworkPropertyMetadata(false, new PropertyChangedCallback(IsMouseHoverSelectedInvalidated)));

        public static bool GetIsMouseHoverSelected(DependencyObject d)
        {
            return (bool)(d.GetValue(StockListBoxItem.IsMouseHoverSelectedProperty));
        }

        public static void SetIsMouseHoverSelected(DependencyObject d, bool value)
        {
            d.SetValue(StockListBoxItem.IsMouseHoverSelectedProperty, value);
        }

        private static void IsMouseHoverSelectedInvalidated(DependencyObject target, DependencyPropertyChangedEventArgs e)
        {
            if (target == null)
                return;
        }
        #endregion

        #region Dependency Properties IsEven

        public static readonly DependencyProperty IsEvenProperty = DependencyProperty.RegisterAttached("IsEven",
            typeof(bool), typeof(StockListBoxItem), new FrameworkPropertyMetadata(false, new PropertyChangedCallback(IsEvenInvalidated)));

        public static bool GetIsEven(DependencyObject d)
        {
            return (bool)(d.GetValue(StockListBoxItem.IsEvenProperty));
        }

        public static void SetIsEven(DependencyObject d, bool value)
        {
            d.SetValue(StockListBoxItem.IsEvenProperty, value);
        }

        private static void IsEvenInvalidated(DependencyObject target, DependencyPropertyChangedEventArgs e)
        {
            if (target == null)
                return;
        }
        #endregion

        #region Dependency Properties IsNegative

        public static readonly DependencyProperty IsNegativeProperty = DependencyProperty.RegisterAttached("IsNegative",
            typeof(bool), typeof(StockListBoxItem), new FrameworkPropertyMetadata(false, new PropertyChangedCallback(IsNegativeInvalidated)));

        public static bool GetIsNegative(DependencyObject d)
        {
            return (bool)(d.GetValue(StockListBoxItem.IsNegativeProperty));
        }

        public static void SetIsNegative(DependencyObject d, bool value)
        {
            d.SetValue(StockListBoxItem.IsNegativeProperty, value);
        }

        private static void IsNegativeInvalidated(DependencyObject target, DependencyPropertyChangedEventArgs e)
        {
            if (target == null)
                return;
        }
       #endregion
    }

	public partial class StockChart3D : Grid
	{
		
		public StockChart3D()
		{
			// This assumes that you are navigating to this scene.
			// If you will normally instantiate it via code and display it
			// manually, you either have to call InitializeComponent by hand or
			// uncomment the following line.
			this.InitializeComponent();

			// Insert code required on object creation below this point.
        }

        private void OnLoaded(object sender, EventArgs e)
        {
            if (sender == null)
                return;

            _XmlData = this.FindResource("myData") as XmlDataProvider;

            GraphList3D.LabelXBrush = this.FindResource("ValuationLabel") as Brush;
            GraphList3D.LabelZBrush = this.FindResource("SectorLabel") as Brush;
            GraphList3D.DowLabelBrush = this.FindResource("SectorLabel") as Brush;

            GraphList3D.ItemSelected += new List3D.SelectedEventHandler(OnList3DItemSelected);
            GraphList3D.ItemUnSelected += new List3D.SelectedEventHandler(OnList3DItemUnSelected);
            GraphList3D.ItemHovered += new List3D.SelectedEventHandler(OnList3DItemHovered);
            GraphList3D.ItemUnHovered += new List3D.SelectedEventHandler(OnList3DItemUnHovered);
            GraphList3D.LoadedCompleted += new List3D.SelectedEventHandler(GraphList3D_LoadedCompleted);
            
        }

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
        #endregion

        #region Events

        void OnList3DItemSelected(object sender, EventArgs e)
        {
           List3DItem li = sender as List3DItem;

           if (li == null)
               return;

           string id = XmlGraphHelper.GetID(li.XmlData);
           OnItemSelected(id, new EventArgs()); 
        }

        void OnList3DItemUnSelected(object sender, EventArgs e)
        {
            OnItemUnSelected(null, new EventArgs());
        }

        void OnList3DItemHovered(object sender, EventArgs e)
        {
            List3DItem li = sender as List3DItem;

            if (li == null)
                return;

            string id = XmlGraphHelper.GetID(li.XmlData);

            // display sector\valuation labels
            string[] s = id.Split(new char[] { ',' });
            GraphList3D.LabelValueBrush = this.FindResource(s[0]) as Brush;
            GraphList3D.LabelSectorBrush = this.FindResource(s[1]) as Brush;

            // fire hovered event
            OnItemHovered(id, new EventArgs());
        }

        void OnList3DItemUnHovered(object sender, EventArgs e)
        {
            List3DItem li = sender as List3DItem;

            if (li == null)
                return;

            GraphList3D.LabelValueBrush = null;
            GraphList3D.LabelSectorBrush = null;

            string id = XmlGraphHelper.GetID(li.XmlData);
            OnItemUnHovered(id, new EventArgs());
        }

        void GraphList3D_LoadedCompleted(object sender, EventArgs e)
        {
            OnLoadedCompleted(null, new EventArgs());
        }

        #endregion

        #region Public Methods

        public int GetScaleFromItem(string ID)
        {
            List3DItem li = GraphList3D.FindList3DItem(ID);

            if (li == null)
                return 0;

            return XmlGraphHelper.GetScale(li.XmlData);
        }

        public void ResetTrackball()
        {
            GraphList3D.ResetTrackball();
        }

        public void SelectItem (string ID)
        {
            GraphList3D.SelectItem(ID);
        }

        public void HoverItem(string ID)
        {
            // display sector\valuation labels
            string[] s = ID.Split(new char[] { ',' });
            GraphList3D.LabelValueBrush = this.FindResource(s[0]) as Brush;
            GraphList3D.LabelSectorBrush = this.FindResource(s[1]) as Brush;

            GraphList3D.HoverItem(ID);
        }

        public void SetGraphHistoryPoint(int index)
        {
            if (index < 0)
                return;

            GraphList3D.GraphHistory(index, _XmlData);
        }

        public void ShowDow(int index)
        {
            // GraphList3D.RotateModelAxisX(); //testing FPS

            if (index < 0)
                return;

            if (_DowToggleState == false)
            {
                _DowToggleState = true;
                GraphList3D.GraphDowHistory(index, _XmlData);
            }
            else
            {
                _DowToggleState = false;
                GraphList3D.GraphDowHistory(-1, _XmlData);
            }
        }

        public void SetGraphType(int graph)
        {
            _DowToggleState = false;

            GraphList3D.GraphReset();

            if (graph == 0)
            {
                _XmlData = this.FindResource("myData") as XmlDataProvider;
                GraphList3D.List3DState = List3DGraphItemStates.Cube;
            }
            else
            {
                _XmlData = this.FindResource("myData2") as XmlDataProvider;
                GraphList3D.List3DState = List3DGraphItemStates.Cylinder;
            }

            Binding myBinding = new Binding();
            myBinding.Mode = BindingMode.OneTime;
            myBinding.Source = _XmlData;
            myBinding.XPath = "CurrentDay/Item";

            GraphList3D.SetBinding(ItemsControl.ItemsSourceProperty, myBinding);

        }

        #endregion

        #region Globals
        bool _DowToggleState = false;

        XmlDataProvider _XmlData;
        #endregion
    }

    public class IsNegativeConverter : IValueConverter
    {
        public IsNegativeConverter()
        {
            //System.Diagnostics.Debug.WriteLine("ChartVisualConverter Initialized");
        }

        public object Convert(
            object value,
            Type targetType,
            object parameter,
            CultureInfo cultureInfo)
        {
            if (targetType == typeof(object) && value is string)
            {
                string amount = value as string;

               double d =  System.Convert.ToDouble(amount);
               if (d >= 0)
               {
                   return (false);
               }
               else
                return (true);
            }
            else
            {
                return DependencyProperty.UnsetValue;
            }
        }

        public object ConvertBack(
            object value,
            Type targetType,
            object parameter,
            CultureInfo cultureInfo)
        {
            //if (targetType == typeof(Double) && value is Nullable<Double>)
            //{
            //    Nullable<Double> nullableValue = (Nullable<Double>)value;

            //    if (nullableValue.HasValue)
            //    {
            //        return nullableValue.Value;
            //    }
            //}

            return DependencyProperty.UnsetValue;
        }
    }

    public class StockImageConverter : System.Windows.Data.IValueConverter
    {
        public object Convert(object o, Type type, object param, CultureInfo cul)
        {
            ImageSourceConverter cov = new ImageSourceConverter();
            string uriStr = o as String;
            return cov.ConvertFrom(uriStr);
        }

        public object ConvertBack(object o, Type type, object param, CultureInfo cul)
        {
            return null;
        }
    }
}
