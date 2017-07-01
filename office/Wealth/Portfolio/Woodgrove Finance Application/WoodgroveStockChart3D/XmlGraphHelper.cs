using System;
using System.Collections.Generic;
using System.Text;
using System.Xml;

namespace WoodgroveFinanceStockChart3D
{
    public class XmlGraphHelper
    {
        public static string GetID(XmlElement xe)
        {
            string id=null;

            if (xe == null)
                return id;

            XmlNodeList xnl = xe.GetElementsByTagName("ID");
            XmlNode xn = xnl[0];

            if (xn != null)
            {
                id = xn.InnerText;
            }

            return id;
        }

        public static int GetColumn(XmlElement xe)
        {
            int column = 0;

            if (xe == null) 
                return column;

            XmlNodeList xnl = xe.GetElementsByTagName("Column");
            XmlNode xn = xnl[0];

            if (xn != null)
            {
                column = Convert.ToInt32(xn.InnerText);
            }

            return column;
        }

        public static int GetRow(XmlElement xe)
        {
            int row = 0;

            if (xe == null)
                return row;

            XmlNodeList xnl = xe.GetElementsByTagName("Row");
            XmlNode xn = xnl[0];

            if (xn != null)
            {
                row = Convert.ToInt32(xn.InnerText);
            }

            return row;
        }

        public static double GetHeight(XmlElement xe)
        {
            double height = 0;

            if (xe == null)
                return height;

            XmlNodeList xnl = xe.GetElementsByTagName("Height");
            XmlNode xn = xnl[0];

            if (xn != null)
            {
                height = Convert.ToDouble(xn.InnerText);
            }

            return height;
        }

        public static int GetScale(XmlElement xe)
        {
            int column = 0;

            if (xe == null)
                return column;

            XmlNodeList xnl = xe.GetElementsByTagName("Scale");
            XmlNode xn = xnl[0];

            if (xn != null)
            {
                column = Convert.ToInt32(xn.InnerText);
            }

            return column;
        }
        public static string GetEquitySymbol(XmlElement xe)
        {
            string symbol = null;

            if (xe == null)
                return symbol;

            XmlNodeList xnl = xe.GetElementsByTagName("Symbol");
            XmlNode xn = xnl[0];
            if (xn != null)
            {
                symbol = xn.InnerText;
            }

            return symbol;

        }

        public static string GetEquityValuationType(XmlElement xe)
        {
            string symbol = null;

            if (xe == null)
                return symbol;

            XmlNodeList xnl = xe.GetElementsByTagName("ValCat");
            XmlNode xn = xnl[0];
            if (xn != null)
            {
                symbol = xn.InnerText;
            }

            return symbol;

        }

        public static string GetEquitySectorType(XmlElement xe)
        {
            string symbol = null;

            if (xe == null)
                return symbol;

            XmlNodeList xnl = xe.GetElementsByTagName("Sector");
            XmlNode xn = xnl[0];
            if (xn != null)
            {
                symbol = xn.InnerText;
            }

            return symbol;
        }

    }
}
