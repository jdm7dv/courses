/* 
 * Set the height of the left navigation. This will adjust 
 * the height according to content height.
 */

function setDivHeight() {
	var offset = document.getElementById("footerDiv").offsetTop;
	document.getElementById("leftNavDiv").style.height = offset-106 + "px";
}

function returnLink (url, w, h) {
    var left = ( screen.width - w ) / 2;
    var top = ( screen.height - h ) / 2;
    
    window.open(url, "popup", "left=" + left + ", top=" + top + ", width=" + w + ", height=" + h + ", resizable=1, scrollbars, toolbar=0, menubar=0");
}  
