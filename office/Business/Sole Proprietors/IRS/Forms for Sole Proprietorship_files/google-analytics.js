var _gaq = _gaq || [];
var pluginUrl =
	'//www.google-analytics.com/plugins/ga/inpage_linkid.js';
_gaq.push(['_require', 'inpage_linkid', pluginUrl]);
_gaq.push(['_setAccount', 'UA-22588183-6']);
_gaq.push (['_gat._anonymizeIp']);
_gaq.push(['_setDomainName', 'irs.gov']);
_gaq.push(['_setAllowLinker', true]);


var url = window.location.href;
if(url.indexOf("/search?") > -1)
{
	if(document.getElementById("noresults"))
	{
		var search_url_path = url.substring(url.indexOf("/search?")) + "&result=nosearchresults";
		_gaq.push(['_trackPageview', search_url_path]);
	}
	else
	{
		var search_url_path = url.substring(url.indexOf("/search?")) + "&result=searchresults";
		_gaq.push(['_trackPageview', search_url_path]);
	}
}
else
{
	_gaq.push(['_trackPageview']);
}

(function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();
