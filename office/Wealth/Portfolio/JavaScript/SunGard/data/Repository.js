//// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF 
//// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO 
//// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A 
//// PARTICULAR PURPOSE. 
//// 
//// Copyright (c) Microsoft Corporation. All rights reserved     
////
//// To see the topic that inspired this sample app, go to http://msdn.microsoft.com/en-us/library/windows/apps/dn163530

(function () {
    "use strict";

    // On first run the application will create a JSON file to store, update
    // and retrieve data from. This is the default data set used to create
    // that file.
    var sampleData = {

        client: {

            id: '123456789',

            photo: '/images/john_e_doe.jpg',

            lastModified: 'Fri Jan 18 2013 14:36:22 GMT-0800 (PST)',

            name: {
                first: 'Jonathan',
                last: 'Moore',
                mi: 'D.',
                posessive: 'Jon\'s'
            },

            contact: [
                { type: 'home',     value: '404-555-1212'      },
                { type: 'mobile',   value: '404-666-1212'      },
                { type: 'business', value: '404-777-2323x12'   },
                { type: 'email',    value: 'jdm7dv@gmail.com' }
            ],

            family: [
                { name: { first: 'Kathy', last: 'Doe', mi: null }, relationship: 'spouse' },
                { name: { first: 'Jim',   last: 'Doe', mi: 'E.' }, relationship: 'child' },
                { name: { first: 'Sara',  last: 'Doe', mi: null }, relationship: 'child' }
            ],

            interests: [
                'John and Kathy coach youth sport teams',
                'John is an avid golfer and on the board of Bushwood Country Club'
            ],

            portfolio: [
                {
                    account_type: '401k',
                    value: 0,
                    allocations: [
                        {
                            category: 'Domestic Stocks',
                            value: 1,
                            holdings: [
                                { name: 'Microsoft MSFT', value: 31000, memo: '' },
                                { name: 'Adobe ADBE', value: 22000, memo: '' }
                            ]
                        },
                        {
                            category: 'Foreign Stocks',
                            value: 1,
                            holdings: [
                                { name: 'Shanghai SE', value: 10027, memo: '' },
                                { name: 'Ashland Bank Intl', value: 8000, memo: '' },
                                { name: 'Ashland Bank F500', value: 4000, memo: '' }
                            ]
                        },
                        {
                            category: 'Bonds',
                            value: 1,
                            holdings: [
                                { name: 'Ashland Bank Shield', value: 11000, memo: '' },
                                { name: 'Ashland Bank USB', value: 12473, memo: '' }
                            ]
                        }
                    ]
                },
                {
                    account_type: 'IRA',
                    value: 0,
                    allocations: [
                        {
                            category: 'Domestic Stocks',
                            value: 1,
                            holdings: [
                                { name: 'First Natl S&P 500', value: 10000, memo: '' },
                                { name: 'First Natl Emerging', value: 8200, memo: '' },
                                { name: 'First Natl Growth', value: 4202, memo: '' }
                            ]
                        },
                        {
                            category: 'Foreign Stocks',
                            value: 1,
                            holdings: [
                                { name: 'First Natl Nikkei 225', value: 4027, memo: '' },
                                { name: 'First Natl Foreign', value: 1400, memo: '' }
                            ]
                        },
                        {
                            category: 'Bonds',
                            value: 1,
                            holdings: [
                                { name: 'First Natl TB MKTF', value: 1200, memo: '' },
                                { name: 'First Natl LTBF', value: 2230, memo: '' }
                            ]
                        }
                    ]
                },
                {
                    account_type: 'taxable',
                    value: 0,
                    allocations: [
                        {
                            category: 'real estate',
                            value: 1,
                            holdings: [
                                { name: '3434 West Hill Drive', value: 340000, memo: '' }
                            ]
                        },
                        {
                            category: 'fixed assets',
                            value: 1,
                            holdings: [
                                { name: 'Sporty Automobile', value: 15000, memo: '' },
                                { name: 'Laptop PC', value: 1600, memo: '' },
                                { name: 'Office Furniture', value: 8000, memo: '' },
                                { name: 'File Server', value: 8200, memo: '' }
                            ]
                        },
                        {
                            category: 'equity',
                            value: 1,
                            holdings: [
                                { name: 'Microsoft Corp.', value: 2800, memo: '' },
                                { name: 'Hamlin Bank', value: 18000, memo: '10 year 3.3%' },
                                { name: 'Janis Intl.', value: 7000, memo: '5 year 4.2%' },
                                { name: 'Holdings Bank', value: 4000, memo: '1 year 2.3%' }
                            ]
                        },
                        {
                            category: 'cash',
                            value: 1,
                            holdings: [
                                { name: 'Bank of America', value: 18000, memo: '' },
                                { name: 'Wells Fargo Bank', value: 7000, memo: '' },
                            ]
                        }
                    ]
                }
            ],

            retirement: {

                current_assets: 0,

                current_liabilities: 260000,

                rate_of_asset_growth: .05,

                rate_of_liability_decline: .1,

                taxable_rate: .2,

                accounts: {
                    client_income: { label: 'John\'s Income', value: 90000, start: 2010, end: 2035 },
                    spouse_income: { label: 'Kathy\'s Income', value: 120000, start: 2010, end: 2035 },
                    ss_income: { label: 'Social Security Income', value: 65000, start: 2042, end: 2065 },
                    living_expenses: { label: 'Living Expenses', value: -80000, start: 2010, end: 2065 },
                    medical_expenses: { label: 'Medical Expenses', value: -15000, start: 2010, end: 2065 }
                },

                controls: {
                    retirement_age_client: { label: 'Retirement Age', type: 'range', min: 33, max: 100, value: 65 },
                    retirement_age_spouse: { label: 'Spouse\'s Retirement Age', type: 'range', min: 33, max: 100, value: 65 },
                    living_expenses: { label: 'Annual Retirement Spending', type: 'range', min: 0, max: 120000, value: 60000 },
                    medical_expenses: { label: 'Additional Spending', type: 'range', min: 0, max: 12000, value: 10000 },
                    years_to_project: { label: 'Age Analysis Ends', type: 'range', min: 33, max: 100, value: 85 },
                    incl_social_security: { label: 'Social Security Benefits', type: 'WinJS.UI.ToggleSwitch', value: false }
                }
            }
        }
    };

    /**
     * The Repository is our local data service. It provides filesystem access,
     * and an API for storing and retrieving JSON data.
     *
     * In this application the only class that has access to the Repository is
     * MediaModel. The goal here is to be able to switch the Repository class
     * out for some other service (ie. a remote web service) without impacting
     * the rest of the application.
     */
    var Repository = WinJS.Class.define(

            function () {
                this._cache = sampleData;
            },

            {
                /**
                 * Returns all of the current data as a JSON object
                 */
                getData: function () {
                    return WinJS.Promise.wrap(this._cache);
                },

                /**
                 * Persist changes to the data set
                 */
                update: function (value) {
                    this._cache.client = value;
                }
            }
    );

    WinJS.Namespace.define('Data', {
        Repository: new Repository()
    });

}());