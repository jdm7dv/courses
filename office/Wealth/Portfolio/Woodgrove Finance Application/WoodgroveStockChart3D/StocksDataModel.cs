using System;
using System.ComponentModel;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Media3D;
using System.Net;
using System.Text;
using System.Collections.ObjectModel;
using System.Xml;

namespace WoodgroveFinanceStockChart3D
{

    public class StocksPopupData : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public StocksPopupData()
        {			
            _StocksItems = new StocksItemCollection();
            _StocksItems.StocksItemCostChanged += new EventHandler(OnStocksItemCostChanged);
        }

        #region Properties

        public string Name
        {
            get { return _Name; }
            set
            {
                _Name = value;
                NotifyPropertyChanged("Name");
            }
        }

        public int TotalExpenses
        {
            // calculated property, no setter
            get { return _totalExpenses; }
        }

        public StocksItemCollection StocksItems
        {
            get { return _StocksItems; }
        }

        #endregion

        #region Public

        public void AddXmlItem(XmlNode xn)
        {
            if (xn == null)
                return;

            XmlElement xe = xn as XmlElement;

            string symbol = XmlGraphHelper.GetEquitySymbol(xe);

            if (FindStocksFromID(symbol) == null)
            {
                StockItem si = new StockItem();
                si.ID = symbol;
                si.Title = symbol;
                StocksItems.Add(si);
            }
        }

        public StockItem FindStocksFromID(string id)
        {
            StockItem piRet = null;

            // find Stocks
            foreach (StockItem pi in _StocksItems)
            {
                if (pi.ID == id)
                {
                    piRet = pi;
                    break;
                }
            }

            return piRet;
        }

        #endregion

        #region Private

        private void OnStocksItemCostChanged(object sender, EventArgs e)
        {
            RecalculateTotalExpense();
        }

        private void RecalculateTotalExpense()
        {
            _totalExpenses = 0;
            /*
            foreach (StocksItem item in StocksItems)
            {
                _totalExpenses += item.Price;
            }
            */
            NotifyPropertyChanged("TotalExpenses");
        }

        private void NotifyPropertyChanged(string propName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propName));
            }
        }

        #endregion Private

        #region Globals

        private string _Name="test2";
        private StocksItemCollection _StocksItems;
		private int _totalExpenses;

        #endregion Globals
    }

    public class StockItem : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        public string ID
        {
            get { return _ID; }
            set
            {
                _ID = value;
                NotifyPropertyChanged("ID");
            }
        }

        public string Description
        {
            get { return _description; }
            set
            {
                _description = value;
                NotifyPropertyChanged("Description");
            }
        }

        public string Price
        {
            get { return _Price; }
            set
            {
                _Price = value;
                NotifyPropertyChanged("Price");
            }
        }

        public string Title
        {
            get { return _Title; }
            set
            {
                _Title = value;
                NotifyPropertyChanged("Title");
            }
        }

        private void NotifyPropertyChanged(string propName)
        {
            if (PropertyChanged != null)
            {
                PropertyChanged(this, new PropertyChangedEventArgs(propName));
            }
        }

        private string _ID = "Default ID";
        private string _Title = "Default Title";
        private string _description = "Default Description";
        private string _Price = "$0.0";
    }
	
    public class StocksItemCollection : ObservableCollection<StockItem>
    {
        public event EventHandler StocksItemCostChanged;

        public new void Add(StockItem item)
        {
            if (item != null)
            {
                item.PropertyChanged += new PropertyChangedEventHandler(StocksItemPropertyChanged);
            }
            base.Add(item);
        }

        private void StocksItemPropertyChanged(object sender, PropertyChangedEventArgs e)
        {
            if (e.PropertyName == "Cost")
            {
                RaiseStocksItemCostChanged(this, new EventArgs());
            }
        }

        void RaiseStocksItemCostChanged(object sender, EventArgs args)
        {
            if (StocksItemCostChanged != null)
            {
                StocksItemCostChanged(sender, args);
            }
        }
    }

}




