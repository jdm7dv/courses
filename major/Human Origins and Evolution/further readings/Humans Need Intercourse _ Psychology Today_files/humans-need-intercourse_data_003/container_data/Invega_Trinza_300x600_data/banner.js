// JavaScript Document
//HTML5 Ad Template JS from DoubleClick by Google

//Declaring elements from the HTML i.e. Giving them Instance Names like in Flash - makes it easier
var container;
var content;
var background; 	  
var ctaButton; 
var textCta;		
var text1;
var text2;
var text3;
var text4;
var text5;
var text6;
var logo;
var prc;
var blueAngle
var tlMain;
//var clickTag = "[ClickThroughURL]";
function loadScript(url, callback)
{
    // Adding the script tag to the head as suggested before
    var head = document.getElementsByTagName('head')[0];
    var script = document.createElement('script');
    script.type = 'text/javascript';
    script.src = url;

    // Then bind the event to the callback function.
    // There are several events for cross browser compatibility.
    script.onreadystatechange = callback;
    script.onload = callback;

    // Fire the loading
    head.appendChild(script);
};

//Function to run with any animations starting on load, or bringing in images etc
init = function()
{
	//Assign All the elements to the element on the page
	container = document.getElementById('container_dc');
	content = document.getElementById('content_dc');
	blueAngle = document.getElementById('blueAngle')
	background = document.getElementById('background');
	ctaButton = document.getElementById('ctaButton');
	prc = document.getElementById('prc');
	textCta = document.getElementById('textCta');
	text1 = document.getElementById('text1');
	text2 = document.getElementById('text2');
	text3 = document.getElementById('text3');
	text4 = document.getElementById('text4');
	text5 = document.getElementById('text5');
	text6 = document.getElementById('text6');
	logo = document.getElementById('logo');
	isi = document.getElementById('scrolling_isi');
	isisBottom = document.getElementById('bottomISILinks');
	
	bigButton = document.getElementById('bigButton');
	
	TweenMax.ticker.fps(24);		

	var tlScrollingIsi = new TimelineMax();
	tlScrollingIsi.paused(true)	
	
	tlScrollingIsi.addLabel("scrollIsi");
	tlScrollingIsi.fromTo(scrolling_isi, 13, {scrollTo:{y:0}},{scrollTo:{y:483}, ease:Linear.easeNone}, "scrollIsi+=2");	
	
	var keyFrameDur = 3;
	var keyFrameDelay = "+=1";
					
	tlMain = new TimelineMax();
	tlMain.paused(true)
	//tlMain.set([text1, text2, glow1, glow2 ], {opacity:0, scale:1}, "start")
	//tlMain.set(ctaButton, {opacity:0, bottom:-40}, "start")

	// 1) text 1
	tlMain.addLabel("transIn1", "+=.5")
	tlMain.fromTo([blueAngle], 1, {top:600,}, {top:254}, "transIn1")
	tlMain.to([text1], .5, {opacity:1, delay:.5}, "transIn1")
	tlMain.to([text1], .45, {opacity:0, delay:3.5}, "transIn1")
	tlMain.fromTo([logo], .5, {opacity:0}, {opacity:1, delay:3.5}, "transIn1")
	tlMain.fromTo([isi], .5, {opacity:0}, {opacity:1, delay:3.5}, "transIn1")
	tlMain.fromTo([isisBottom], .5, {opacity:0}, {opacity:1, delay:3.5}, "transIn1")
	
	// 2) text 2
	tlMain.addLabel("transIn2", "+=0.25");
	tlMain.fromTo([text2], .5, {opacity:0}, {opacity:1, }, "transIn2")
	
	// 3) text 3 and tablet
	tlMain.addLabel("transOut2", "+=3.25")
	tlMain.to(text2, .5, {opacity:0}, "transOut2")

	tlMain.addLabel("transIn3", "+=.5")
	tlMain.fromTo(text3, .5, {opacity:0}, {opacity:1}, "transIn3")

	tlMain.addLabel("transOut3", "+=2.5")
	tlMain.to(text3, .5, {opacity:0}, "transOut3")

	tlMain.addLabel("transIn4", "+=.5")
	tlMain.fromTo(prc, .25, {opacity:1}, {opacity:0}, "transIn4")
	tlMain.fromTo(text4, .5, {opacity:0}, {opacity:1}, "transIn4")
	tlMain.fromTo(text5, .5, {opacity:0, left:-92}, {opacity:1,left:37, delay:.75}, "transIn4")
	tlMain.fromTo(text6, .5, {opacity:0}, {opacity:1, delay:1.25}, "transIn4")
	tlMain.fromTo(ctaButton, .5, {left:-100}, {left:-15, delay:1.50}, "transIn4")

	
	//Show Ad
	container.style.display = "block";
	tlMain.paused(false)

}

loadScript("https://cdnjs.cloudflare.com/ajax/libs/gsap/1.15.1/plugins/ScrollToPlugin.min.js");
loadScript("https://cdnjs.cloudflare.com/ajax/libs/gsap/latest/TweenMax.min.js", init);