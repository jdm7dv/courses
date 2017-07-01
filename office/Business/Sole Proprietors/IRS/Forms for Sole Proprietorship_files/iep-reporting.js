// A script that includes other javascript resources on the page.

// Included Scripts
include_js('/static_assets/js/reporting','google-analytics.js');
include_js('/static_assets/js/foresee', 'foresee-trigger.js');
include_js('/static_assets/js/leftnav', 'height.js');
include_js('/static_assets/js', 'https.js');


function include_js(path, filename) {
	var location = path + "/" + filename;
	var head_dom = document.getElementsByTagName('head').item(0);
	var js = document.createElement('script');
	js.type = 'text/javascript';
	js.src = location;
	head_dom.appendChild(js);
}

// Federated Analytics
include_fed('/static_assets/js/reporting','federated-analytics.js?agency=Treasury&subagency=IRS&sdor=true');

function include_fed(path, filename) {
	var location = path + "/" + filename;
	var head_dom = document.getElementsByTagName('head').item(0);
	var js = document.createElement('script');
	js.id = '_fed_an_ua_tag';
	js.type = 'text/javascript';
	js.src = location;
	head_dom.appendChild(js);
}

