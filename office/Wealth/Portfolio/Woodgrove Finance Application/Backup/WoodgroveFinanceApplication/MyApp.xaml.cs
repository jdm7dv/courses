using System;
using System.Windows;
using System.Windows.Navigation;
using System.Data;
using System.Xml;
using System.Configuration;
using System.Windows.Interop;

namespace WoodgroveFinanceApplication
{
    /// <summary>
    /// Interaction logic for MyApp.xaml
    /// </summary>

    public partial class MyApp : Application
    {

        //  Can be used at runtime to determine if running as XBAP
        static public bool IsXBAP
        {
            get
            {
                return BrowserInteropHelper.IsBrowserHosted;
            }
        }
    }
}