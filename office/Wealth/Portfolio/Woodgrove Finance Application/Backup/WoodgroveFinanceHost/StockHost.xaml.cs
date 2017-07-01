using System;
using System.IO;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Media.Animation;
using System.Windows.Navigation;
using System.Windows.Controls.Primitives;
using System.Windows.Input;
using System.Xml;
using System.Collections;
using WoodgroveFinanceStockChartFrame;
using WoodgroveFinanceStockChart3D;
using System.Windows.Threading;
using System.Configuration;
namespace WoodgroveFinanceHost
{
    

    public partial class StockHost : Grid
	{
		
		public StockHost()
		{
			 this.InitializeComponent();
        }

        private void OnLoaded(object sender, EventArgs e)
        {
            if (sender == null)
                return;
            // StockChart3D item selected event handler
            StockChart3D.ItemSelected += new StockChart3D.SelectedEventHandler(StockChart3D_ItemSelected);
            StockChart3D.ItemUnSelected += new StockChart3D.SelectedEventHandler(StockChart3D_ItemUnSelected);
            StockChart3D.ItemHovered += new StockChart3D.SelectedEventHandler(StockChart3D_ItemHovered);
            StockChart3D.ItemUnHovered += new StockChart3D.SelectedEventHandler(StockChart3D_ItemUnHovered);
            StockChart3D.LoadedCompleted += new StockChart3D.SelectedEventHandler(StockChart3D_LoadedCompleted);
            StockChart3D.MouseLeave += new MouseEventHandler(StockChart3D_MouseLeave);
            // Setup Popup
            _Popup = new Popup();
            Grid grid = this.FindResource("PopupGrid") as Grid;
            _Popup.Child = grid;
            _Popup.PlacementTarget = StockChart3D;
            _Popup.Placement = PlacementMode.RelativePoint;
            _Popup.DataContext = this.DataContext;
            _Popup.Focusable = false;
            _Popup.AllowsTransparency = true;

            ListView.UnselectAll();
            ListView1.UnselectAll();
            ListView2.UnselectAll();

            _HoverList = new ArrayList();
            _SelectionList = new ArrayList();

            // Use a timer to auto scroll the grid
            _timer = new DispatcherTimer();
            _timer.Interval = new System.TimeSpan(0, 0, 0, 1, 0); 
            _timer.Tick += new System.EventHandler(OnTimerEvent);
            _timer.Stop();

        }

        #region Events

        void StockChart3D_MouseLeave(object sender, MouseEventArgs e)
        {
            _timer.Stop();
        }


        void StockChart3D_LoadedCompleted(object sender, EventArgs e)
        {
            SelectionChangeWithValueSector("Small Cap Growth", "Consumer");
        }

        void OnTimerEvent(object sender, System.EventArgs args)
        {
            _timer.Stop();

            if (_Popup == null)
                return;

           
            _Popup.IsOpen = true;
        }

        void ListView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            StockListBox slb = sender as StockListBox;
            if ((slb == null) || (_SelectionList == null))
                return;
            
            if (e.AddedItems.Count > 0)
            {

                XmlElement xe = e.AddedItems[0] as XmlElement;
                if (xe == null)
                    return;

                string valuation = XmlGraphHelper.GetEquityValuationType(xe);
                string sector = XmlGraphHelper.GetEquitySectorType(xe);

                
                SelectionChangeWithValueSector(valuation, sector);
             }
        }

        void ListView_ItemHilight(object sender, EventArgs e)
        {
            StockListBoxItem slbi = sender as StockListBoxItem;
            if (slbi == null)
                return;

            
            //DependencyObject dob = sender as DependencyObject;
            XmlElement xe = slbi.Content as XmlElement;

            string valuation = XmlGraphHelper.GetEquityValuationType(xe);
            string sector = XmlGraphHelper.GetEquitySectorType(xe);

            _HoverList.Clear();
            FindSymbolsByValueAndSector(_HoverList, ListView, valuation, sector);
            FindSymbolsByValueAndSector(_HoverList, ListView1, valuation, sector);
            FindSymbolsByValueAndSector(_HoverList, ListView2, valuation, sector);

            string id = valuation + "," + sector;
            StockChart3D.HoverItem(id);
            DayScalePointerTranslate.Y = StockChart3D.GetScaleFromItem(id) * -1;

            // unselect previous hover state
            UnHoverSelected(ListView);
            UnHoverSelected(ListView1);
            UnHoverSelected(ListView2);

            // select the hover state
            for (int i = 0; i < _HoverList.Count; i++)
            {
                string symbol = _HoverList[i] as string;
                HoverSelected(ListView, symbol);
                HoverSelected(ListView1, symbol);
                HoverSelected(ListView2, symbol);
            }
        }

        private void OnDJIA(object sender, RoutedEventArgs e)
        {
            StockChart3D.ShowDow((int)Slider.Value);
        }

        private void OnGraph3DTrackballReset(object sender, RoutedEventArgs e)
        {
            StockChart3D.ResetTrackball();
        }

        void OnGraphTypeComboBox(object sender, SelectionChangedEventArgs e)
        {
            ComboBox cb = sender as ComboBox;

            if (cb == null)
                return;

            StockChart3D.SetGraphType(cb.SelectedIndex);
        }

        private void OnHistorySlider_ValueChanged(object sender, RoutedEventArgs e)
        {
            Slider slider = (Slider)sender;

            if (slider == null)
                return;

            StockChart3D.SetGraphHistoryPoint((int)slider.Value);
        }

        private void SetSummaryItemsControlXPathBinding(ArrayList al)
        {
            if ((al == null) || (al.Count == 0))
                return;

            string xpath = "/Portfolio/Equity[";

            for (int i = 0; i < al.Count; i++)
            {
                if ((i > 0) && (i < al.Count))
                    xpath += " or ";

                xpath += " Symbol='" + al[i] + "'";
            }
            xpath += "]/Summary";

            Binding newBinding = new Binding();
            newBinding.XPath = xpath;

            SummaryItemsControl.SetBinding(ItemsControl.ItemsSourceProperty, newBinding);
        }

        void StockChart3D_ItemSelected(object sender, EventArgs e)
        {
            string id = sender as string;
            string[] s;

            _timer.Stop();

            s = id.Split(new char[] { ',' });
            _SelectionList.Clear();
            FindSymbolsByValueAndSector(_SelectionList, ListView, s[0], s[1]);
            FindSymbolsByValueAndSector(_SelectionList, ListView1, s[0], s[1]);
            FindSymbolsByValueAndSector(_SelectionList, ListView2, s[0], s[1]);

            UnSelectListViewItem(ListView);
            UnSelectListViewItem(ListView1);
            UnSelectListViewItem(ListView2);

            // select the items
            for (int i = 0; i < _SelectionList.Count; i++)
            {
                string symbol = _SelectionList[i] as string;
                SelectListViewItem(ListView, symbol);
                SelectListViewItem(ListView1, symbol);
                SelectListViewItem(ListView2, symbol);
            }

            SetSummaryItemsControlXPathBinding(_SelectionList);

            // set scale
            DayScalePointerSelectedTranslate.Y = StockChart3D.GetScaleFromItem(id) * -1;
        }

        void StockChart3D_ItemUnSelected(object sender, EventArgs e)
        {
            string id = sender as string;

            if (_Popup == null)
                return;
            else
                _Popup.IsOpen = false;
            
            this.Cursor = Cursors.Arrow;

            // set scale
            DayScalePointerSelectedTranslate.Y = 0;
        }

        void StockChart3D_ItemHovered(object sender, EventArgs e)
        {
            
            string id = sender as string;
            string[] s;

            _timer.Stop();
             
            s = id.Split(new char[] { ',' });
            _HoverList.Clear();
            FindSymbolsByValueAndSector(_HoverList, ListView, s[0], s[1]);
            FindSymbolsByValueAndSector(_HoverList, ListView1, s[0], s[1]);
            FindSymbolsByValueAndSector(_HoverList, ListView2, s[0], s[1]);

            string xpath = "/Portfolio/Equity[";

            for (int i = 0; i < _HoverList.Count; i++)
            {
                if ((i > 0) && (i < _HoverList.Count))
                    xpath += " or ";

                xpath += " Symbol='" + _HoverList[i] + "'";
            }
            xpath += "]";

            // Setup Popup
            if (_Popup != null)
                _Popup.IsOpen = false;

            string symbolHover = _HoverList[0] as string;
            XmlNode xn = FindListViewItemBySymbol(ListView, symbolHover);
            if (xn == null)
                xn = FindListViewItemBySymbol(ListView1, symbolHover);
            if (xn == null)
                xn = FindListViewItemBySymbol(ListView2, symbolHover);

            Grid g = this.FindResource("PopupGrid") as Grid;
            Grid gChild = g.Children[0] as Grid;
            gChild.DataContext = xn;
            ListBox lb = g.Children[1] as ListBox;
            Binding newBinding = new Binding();
            newBinding.XPath = xpath;

            lb.SetBinding(ItemsControl.ItemsSourceProperty, newBinding);
            
            

            _Popup = new Popup();
            _Popup.Child = g;
            _Popup.PlacementTarget = StockChart3D;
            _Popup.Placement = PlacementMode.RelativePoint;
            _Popup.DataContext = this.DataContext;
            _Popup.Focusable = false;
            _Popup.AllowsTransparency = true;
            Point p = Mouse.GetPosition(StockChart3D);
            _Popup.HorizontalOffset = p.X;
            _Popup.VerticalOffset = p.Y;

            _timer.Start();

            // unselect previous hover state
            UnHoverSelected(ListView);
            UnHoverSelected(ListView1);
            UnHoverSelected(ListView2);

            // select the hover state
            for (int i = 0; i < _HoverList.Count; i++)
            {
                string symbol = _HoverList[i] as string;
                HoverSelected(ListView, symbol);
                HoverSelected(ListView1, symbol);
                HoverSelected(ListView2, symbol);
            }

            // set scale
            DayScalePointerTranslate.Y =  StockChart3D.GetScaleFromItem(id) * -1;
        }

        void StockChart3D_ItemUnHovered(object sender, EventArgs e)
        {
            _timer.Stop();
            _Popup.IsOpen = false;

            // unselect previous hover state
            UnHoverSelected(ListView);
            UnHoverSelected(ListView1);
            UnHoverSelected(ListView2);

            // set scale
            DayScalePointerTranslate.Y = 0;
        }

        #endregion

        #region Private

        private void SelectionChangeWithValueSector(string valuation, string sector)
        {
            string id = valuation + "," + sector;
            StockChart3D.SelectItem(id);

            _SelectionList.Clear();
            FindSymbolsByValueAndSector(_SelectionList, ListView, valuation, sector);
            FindSymbolsByValueAndSector(_SelectionList, ListView1, valuation, sector);
            FindSymbolsByValueAndSector(_SelectionList, ListView2, valuation, sector);

            UnSelectListViewItem(ListView);
            UnSelectListViewItem(ListView1);
            UnSelectListViewItem(ListView2);

            // select the items
            for (int i = 0; i < _SelectionList.Count; i++)
            {
                string symbol = _SelectionList[i] as string;
                SelectListViewItem(ListView, symbol);
                SelectListViewItem(ListView1, symbol);
                SelectListViewItem(ListView2, symbol);
            }

            SetSummaryItemsControlXPathBinding(_SelectionList);

            ListView.SelectedIndex = -1;
            ListView1.SelectedIndex = -1;
            ListView2.SelectedIndex = -1;

            // set scale
            DayScalePointerSelectedTranslate.Y = StockChart3D.GetScaleFromItem(id) * -1;
        }

        private void HoverSelected(StockListBox slb, string symbol)
        {
            // select the hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                XmlElement xe = slb.Items[i] as XmlElement;
                if (xe == null)
                    return;

                string equity = XmlGraphHelper.GetEquitySymbol(xe);

                if (equity == symbol)
                {
                    DependencyObject dob = slb.ItemContainerGenerator.ContainerFromIndex(i);
                    StockListBoxItem slbi = dob as StockListBoxItem;
                    slbi.SetValue(StockListBoxItem.IsMouseHoverSelectedProperty, true);
                }
            }
        }

        private void UnHoverSelected(StockListBox slb)
        {
            // unselect previous hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                DependencyObject dob = slb.ItemContainerGenerator.ContainerFromIndex(i);
                StockListBoxItem slbi = dob as StockListBoxItem;
                bool hoverstate = (bool)slbi.GetValue(StockListBoxItem.IsMouseHoverSelectedProperty);

                if (hoverstate == true)
                {
                    slbi.SetValue(StockListBoxItem.IsMouseHoverSelectedProperty, false);
                }
            }
        }

        private void SelectListViewItem(StockListBox slb, string symbol)
        {
            // select the hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                XmlElement xe = slb.Items[i] as XmlElement;
                if (xe == null)
                    return;

                string equity = XmlGraphHelper.GetEquitySymbol(xe);

                if (equity == symbol)
                {
                    DependencyObject dob = slb.ItemContainerGenerator.ContainerFromIndex(i);
                    StockListBoxItem slbi = dob as StockListBoxItem;
                    slbi.SetValue(StockListBoxItem.IsItemSelectedProperty, true);
                }
            }
        
        }

        private void UnSelectListViewItem(StockListBox slb)
        {
            // select the hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                DependencyObject dob = slb.ItemContainerGenerator.ContainerFromIndex(i);
                StockListBoxItem slbi = dob as StockListBoxItem;

                if (slbi == null)
                    return;

                bool selectedstate = (bool)slbi.GetValue(StockListBoxItem.IsItemSelectedProperty);

                if (selectedstate == true)
                {
                    slbi.SetValue(StockListBoxItem.IsItemSelectedProperty, false);
                }
            }

        }
        private XmlNode FindListViewItemBySymbol(StockListBox slb, string symbol)
        {
            // select the hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                XmlElement xe = slb.Items[i] as XmlElement;
                if (xe == null)
                    return null;

                string equity = XmlGraphHelper.GetEquitySymbol(xe);

                if (equity == symbol)
                {
                    return xe.Clone();
                }
            }
            return null;
        }

        private void FindSymbolsByValueAndSector(ArrayList al, StockListBox slb, string valueType, string sectorType)
        {
            // select the hover state
            for (int i = 0; i < slb.Items.Count; i++)
            {
                XmlElement xe = slb.Items[i] as XmlElement;
                if (xe == null)
                    return;

                string v = XmlGraphHelper.GetEquityValuationType(xe);
                string s = XmlGraphHelper.GetEquitySectorType(xe);
                string equity = XmlGraphHelper.GetEquitySymbol(xe);

                if ((v == valueType) && (s == sectorType))
                {
                    al.Add(equity);
                }
            }
        }

      
        #endregion

        #region Globals
        Popup _Popup=null;
        StocksPopupData _StockData;
        ArrayList _HoverList;
        ArrayList _SelectionList;
        DispatcherTimer _timer = null;
       
        #endregion
    }
}
