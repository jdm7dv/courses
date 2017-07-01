var sites = [
"http://apps.irs.gov/",
"http://apps.irs.gov.edgesuite-staging.net/",
"http://apps2.irs.gov/",
"http://apps3.irs.gov/",
"http://cms.portal.irs.gov/",
"http://eforms.irs.gov/",
"http://faqs.irs.gov/",
"http://faqs.qai.irs.gov/",
"http://fire.irs.gov/",
"http://forms.irs.gov/",
"http://irs.treasury.gov/",
"http://jobs.irs.gov/",
"http://preview.portal.irs.gov/",
"http://prdpreviewvip.portal.local/",
"http://www.addthis.com/",
"http://www.egov.gov/",
"http://www.egrants.irs.gov/",
"http://www.irs.gov/",
"http://www.irs.gov.edgesuite-staging.net/",
"http://www.irs.treasury.gov/",
"http://www.irs.ustreas.gov/",
"http://www.procurement.irs.treas.gov/",
"http://www.search.irs.gov/",
"http://www.stayexempt.irs.gov/",
"http://www.treas.gov/",
"http://www.ustreas.gov/",
"https://excise.irs.gov/",
"https://forms.irs.gov/",
"https://la.www4.irs.gov/",
"https://la1.www4.irs.gov/",
"https://la2.www4.irs.gov/",
"https://rpr.irs.gov/",
"http://sa.www4.irs.gov/",
"https://sa.www4.irs.gov/",
"https://sa1.www4.irs.gov/",
"https://sa2.www4.irs.gov/",
"http://search.irs.gov/",
"http://search.irs.gov.edgesuite-staging.net/",
"http://server.iad.liveperson.net/",
"https://sales.liveperson.net/",
"https://state-excise.irs.gov/",
"https://forms-uat.irs.gov.edgekey-staging.net/",
"https://www.eitc.irs.gov/",
"http://forms-uat.irs.gov.edgekey-staging.net/",
"http://uatlive.portal.irs.gov/",
"http://uatapps.portal.irs.gov/",
"http://uatsearch.portal.irs.gov/",
"http://uatpreview.portal.irs.gov/",
"http://trainpreview.portal.irs.gov/",
"http://www.eitc.irs.gov/",
"https://www.eitc.irs.gov/",
"http://www.marketingexpress.irs.gov/",
"https://directpay.irs.gov/",
"http://prodsearch.portal.irs.gov/",
"http://www.taxpayeradvocate.irs.gov/",
"https://www.taxpayeradvocate.irs.gov/",
"http://www.stayexempt.irs.gov.edgesuite.net/",
"http://stayexempt.staging.portal.irs.gov/",
"https://apps.irs.gov/",
"https://apps.irs.gov.edgesuite-staging.net/",
"https://forms.irs.gov/",
"https://jobs.irs.gov/",
"https://www.addthis.com/",
"https://www.irs.gov/",
"https://www.irs.gov.edgesuite-staging.net/",
"https://www.stayexempt.irs.gov/",
"https://search.irs.gov/",
"https://search.irs.gov.edgesuite-staging.net/",
"https://www.marketingexpress.irs.gov/",
"https://www.stayexempt.irs.gov.edgesuite.net/",
"https://find.irs.gov/",
"http://freefile.irs.gov/",
"http://efile.irs.gov/",
"https://freefile.irs.gov/",
"https://efile.irs.gov/",
"https://m.jobs.irs.gov/",
"https://www.jobs.irs.gov/",
"https://www.m.jobs.irs.gov/",
"https://www.search.irs.gov/",
"https://server.iad.liveperson.net/",
"http://find.irs.gov/" ];

var pageWhitelist = [
"http://www.eitc.irs.gov/Tax-Preparer-Toolkit/ddvideos",
"https://www.eitc.irs.gov/Tax-Preparer-Toolkit/ddvideos" ];

var jsWhitelist = [
"javascript:window.print()"
];
var currentPage = $(location).attr('href');

var isCurrentPage = false;
if (jQuery.inArray(currentPage,pageWhitelist) > -1) {
	isCurrentPage=true;
}

var existTestSites = false;

jQuery(function ($) {

	var languageParam = getLanguageParam();
	appendTestSites();

	$("a").attr("href", function(index) {

	    var thisUrl = this.href;
	    if (!thisUrl) {
	    	return;
	    }

	    var isValidSite = false;
	    var thisUrlSiteIndex = thisUrl.indexOf("/", 8);
		var jsWhitelistIndex = thisUrl.indexOf(")",0);

		if (isCurrentPage) {
			if (printIndex > -1) {
				jsWhitelist.push(thisUrl);
			}
		}
	    if (thisUrlSiteIndex > -1) {

	    	for (siteIndex in sites) {
	    		var thisUrlSite = thisUrl.substr(0, thisUrlSiteIndex + 1);
	    		var site = sites[siteIndex];

	    		if (site.toString().toLowerCase() == thisUrlSite.toLowerCase()) {
	    			isValidSite = true;
	    			break;
	    		}
	    	}
	    } else if (jsWhitelistIndex > -1) {

			for (pop in jsWhitelist) {
				var thisFun = thisUrl.substr(0, jsWhitelistIndex +1);
				var fun = jsWhitelist[pop];

				if (fun.toString().toLowerCase() == thisFun.toLowerCase()){
					isValidSite = true;
					break;
				}
			}

		} else {
	    	var thisUrlMailToIndex = thisUrl.toLowerCase().indexOf("mailto:");

	    	if (thisUrlMailToIndex > -1) {
	    		isValidSite = true;
	    	}
	    }

	    if (!isValidSite) {
            var inner_url = this.innerHTML;
	    	this.href = "//apps.irs.gov/app/scripts/exit.jsp?" + languageParam + "dest=" + thisUrl;
            this.innerHTML = inner_url;
	    }
	});
});

function getLanguageParam() {
	var metaData = document.getElementsByTagName("meta");

	for (var i in metaData) {
		if (metaData[i].name == "language" && metaData[i].content == "es") {
			return "lang=es&";
		}
	}

	return "";
}

function appendTestSites() {
	if (existTestSites == false && typeof testSites != 'undefined') {
		existTestSites = true;
		sites = testSites.concat(sites);
	}
}