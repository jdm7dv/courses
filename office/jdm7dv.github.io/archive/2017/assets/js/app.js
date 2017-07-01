! function (a, b, c) {
    function d(a) {
        $("h4 > a, h4 > .close-btn", a).on(clickEvent, function (a) {
            a.preventDefault(), $(this).parent().parent().toggleClass("open")
        })
    }

    function e() {
        function c(a) {
            var c = b.createElement("div"),
                e = b.createElement("div");
            a.setAttribute("class", "zoom-controls"), c.setAttribute("class", "zoom-controls-in"), e.setAttribute("class", "zoom-controls-out"), a.appendChild(c), a.appendChild(e), google.maps.event.addDomListener(c, "click", function () {
                d.setZoom(d.getZoom() + 1)
            }), google.maps.event.addDomListener(e, "click", function () {
                d.setZoom(d.getZoom() - 1)
            })
        }
        var d, e = function () {
                var e = new google.maps.LatLng(40.6930029, -73.9910843),
                    g = {
                        zoom: 15,
                        minZoom: 13,
                        maxZoom: 17,
                        center: e,
                        disableDefaultUI: !0,
                        scrollwheel: !1,
                        disableDoubleClickZoom: !1,
                        styles: f,
                        scaleControl: !0
                    };
                isMobile && (g.disableDoubleClickZoom = !0, g.draggable = !1), d = new google.maps.Map(b.getElementById("map"), g);
                var h = {
                        url: "/img/pages/contact/map-pin.png",
                        scaledSize: new google.maps.Size(60, 100),
                        anchor: new google.maps.Point(30, 88)
                    },
                    i = new google.maps.Marker({
                        position: e,
                        map: d,
                        icon: h,
                        optimized: !1,
                        zIndex: 100001
                    });
                google.maps.event.addListener(i, "click", function () {
                    a.open("https://www.google.com/maps/place/This+Also/@40.693003,-73.991084,14z/data=!4m2!3m1!1s0x89c2598f1f713593:0xbf96e5d0ba9d9a83", "_blank")
                });
                var j = b.createElement("div");
                new c(j);
                j.index = 1, d.controls[google.maps.ControlPosition.RIGHT_BOTTOM].push(j), viewportWidth < 500 && d.setZoom(14), google.maps.event.addDomListener(a, "optimizedResize", function () {
                    google.maps.event.trigger(d, "optimizedResize"), d.setCenter(e), viewportWidth < 500 ? d.setZoom(14) : d.setZoom(15)
                })
            },
            f = [{
                featureType: "all",
                elementType: "labels",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "water",
                elementType: "geometry.fill",
                stylers: [{
                    visibility: "on"
                }, {
                    color: "#5a59ff"
                }]
            }, {
                featureType: "landscape",
                elementType: "geometry.fill",
                stylers: [{
                    color: "#ffffff"
                }]
            }, {
                featureType: "poi",
                elementType: "all",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "road",
                elementType: "geometry.fill",
                stylers: [{
                    color: "#d5d4d2"
                }, {
                    weight: 1
                }]
            }, {
                featureType: "road",
                elementType: "geometry.stroke",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "road",
                elementType: "labels",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "road.highway",
                elementType: "geometry.stroke",
                stylers: [{
                    visibility: "on"
                }, {
                    color: "#d5d4d2"
                }, {
                    weight: .8
                }]
            }, {
                featureType: "landscape.man_made",
                elementType: "geometry.stroke",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "transit",
                elementType: "all",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "administrative",
                stylers: [{
                    visibility: "off"
                }]
            }, {
                featureType: "landscape",
                elementType: "labels.text.fill",
                stylers: [{
                    color: "#5a59ff"
                }]
            }];
        e()
    }

    function f(a, b) {
        this.selector = a, this.options = b || {
            arrows: !1,
            centerPadding: "23%",
            centerMode: !0,
            slidesToShow: 1,
            focusOnSelect: !0,
            draggable: isMobile
        }, this.init = function () {
            $(this.selector).on("init", function () {
                var a = $(".slick-active");
                a.prev().removeClass("nextdiv").addClass("prevdiv"), a.next().removeClass("prevdiv").addClass("nextdiv"), a.removeClass("nextdiv").removeClass("prevdiv")
            }), $(this.selector).slick(this.options).on("afterChange", function () {
                var a = $(".slick-active");
                a.prev().removeClass("nextdiv").addClass("prevdiv"), a.next().removeClass("prevdiv").addClass("nextdiv"), a.removeClass("nextdiv").removeClass("prevdiv")
            })
        }
    }

    function g(c) {
        var d = b.createElement("script");
        d.src = "https://www.youtube.com/iframe_api";
        var e = b.getElementsByTagName("script")[0];
        e.parentNode.insertBefore(d, e);
        var f = $("#" + c).parent(),
            g = $("#" + c).attr("data-videoid"),
            h = $("#" + c).attr("data-options"),
            j = h.split("&"),
            k = {};
        for (i = 0; i < j.length; i++) {
            var l = j[i].split("=");
            k[l[0]] = l[1]
        }
        this.init = function () {
            function b(a) {
                $(".video-playbtn", f).on("click", function () {
                    $(this).fadeOut(500), $("iframe", f).fadeIn(500), a.target.playVideo()
                })
            }

            function d(a) {
                0 === a.data && ($(".video-playbtn", f).fadeIn(500), $("iframe", f).fadeOut(500))
            }
            a.onYouTubeIframeAPIReady = function () {
                console.log("YouTube API Ready"), this.player = new YT.Player(c, {
                    videoId: g,
                    playerVars: k,
                    events: {
                        onReady: b,
                        onStateChange: d
                    }
                })
            }
        }
    }

    function h(a) {
        var b = $("#" + a).attr("data-videoid");
        this.init = function () {
            $("#" + a).html('<iframe width="480" height="180" scrolling="no" frameborder="no" src="https://w.soundcloud.com/player/?url=https%3A//api.soundcloud.com/tracks/' + b + '&amp;color=000000&amp;auto_play=false&amp;hide_related=false&amp;show_comments=false&amp;show_user=false&amp;show_reposts=false"></iframe>')
        }
    }

    function j(c) {
        function d() {
            for (var a = 0; a < f.length; a++) f[a].style.zIndex = a, f[a].setAttribute("data-order", a), a < f.length - 1 ? f[a].removeClass("active") : f[a].addClass("active")
        }
        var e = b.getElementById(c),
            f = [],
            g = null,
            h = 0,
            i = 0,
            j = 0,
            k = 0,
            l = null,
            m = 0,
            n = 0,
            o = null,
            p = null,
            q = !1;
        this.init = function () {
            function c() {
                q && (ga("send", "event", "Ray Window", "windows clicked", j, {
                    transport: "beacon"
                }), ga("send", "event", "Ray Window", "pixels moved", m + n + "px", {
                    transport: "beacon"
                }), ga("send", "timing", "Ray Window", "time moved", k, {
                    transport: "beacon"
                }))
            }
            for (var r = e.getElementsByClassName("window"), s = r.length; s--; f.unshift(r[s]));
            for (var s = 0; s < f.length; s++) f[s].setAttribute("data-order", s);
            e.addEventListener("mousedown", function (c) {
                if (c.target.hasClass("window")) {
                    if (g = c.target, l = (new Date).getTime(), g.hasAttribute("data-moved") || (j++, q = !0, g.setAttribute("data-moved", !0)), b.all) var k = a.event.clientX,
                        m = a.event.clientY;
                    else var k = c.pageX,
                        m = c.pageY;
                    h = k - g.offsetLeft, i = m - g.offsetTop - (e.getBoundingClientRect().top + b.body.scrollTop);
                    var n = f.indexOf(g),
                        o = f.splice(n, 1);
                    f.push(o[0]), d()
                }
            }, !1), b.addEventListener("mousemove", function (c) {
                if (null !== g) {
                    var d = b.all ? a.event.clientX : c.pageX,
                        f = b.all ? a.event.clientY : c.pageY;
                    g.style.left = d - h + "px", g.style.top = f - i - (e.getBoundingClientRect().top + b.body.scrollTop) + "px", o && (m += Math.abs(d - o)), p && (n += Math.abs(f - p)), o = d, p = f
                }
            }, !1), b.addEventListener("mouseup", function () {
                if (g = null, h = 0, i = 0, o = 0, p = 0, l) {
                    var a = (new Date).getTime();
                    k += a - l, l = null
                }
            }, !1), b.addEventListener("mousedown", function () {
                if (null === g)
                    for (var a = 0; a < f.length; a++) f[a].removeClass("active")
            }, !1), H.addEventListener("page.hidden", function () {
                c(), a.removeEventListener("unload", c)
            }, !1), a.addEventListener("unload", c, !1)
        }
    }

    function k() {
        storedTitleText = "", viewportHeight = a.innerHeight, viewportWidth = a.innerWidth, baseURL = a.location.origin + "/", dragging = !1, renderingEngine = D.getAttribute("data-renderingengine"), supportsCSSAnimation = w(), supportsSVGAnimation = x(), isMobile = "true" === D.getAttribute("data-mobile"), isTouchDevice = "ontouchstart" in b.documentElement, clickEvent = isTouchDevice ? "touchstart" : "click", clickEndEvent = isTouchDevice ? "touchend" : "click", "ontouchstart" in b.documentElement || (D.className += " no-touch"), optimizedScroll = z("scroll", "optimizedScroll"), optimizedResize = z("resize", "optimizedResize"), b.addEventListener("DOMContentLoaded", function () {
            if (Navigator.hash && "" !== Navigator.hash) {
                var c = b.getElementById(Navigator.hash);
                c && (H.addClass("no-animation"), c.parentElement.hasClass("accordion") && (c.addClass("open"), a.scrollTo(0, c.getBoundingClientRect().top), Navigator.hashOnPage = !0))
            }
            if (storedTitleText = b.getElementsByTagName("title")[0].innerHTML, Menu.init(), a.viewportUnitsBuggyfill.init({
                    hacks: a.viewportUnitsBuggyfillHacks
                }), u(), t(), s() && D.addClass("minimal-ui"), $(D).hasClass("error") || Navigator.init(), isMobile && Navigator.isHome()) {
                var d = (new Date).getTime(),
                    e = 1e3,
                    f = b.getElementById("video"),
                    g = f.getAttribute("data-source"),
                    h = new Whitewater(f, g, {
                        autoplay: !0,
                        loop: !0
                    });
                f.addEventListener("whitewaterload", function () {
                    function a() {
                        I.setAttribute("data-videoready", "true"), h.play(), H.addEventListener("page.hidden", function () {
                            h = null, f.parentNode.removeChild(f)
                        }, !1)
                    }
                    var b = (new Date).getTime();
                    if (b - d >= e) a();
                    else {
                        var c = b - d;
                        setTimeout(a, e - c)
                    }
                }, !1)
            }
            A()
        }, !1), D.addEventListener("touchmove", function () {
            dragging = !0
        }, !1), D.addEventListener("touchstart", function () {
            dragging = !1
        }, !1), J.addEventListener("canplaythrough", function () {
            Navigator.isHome() && o()
        }, !1), a.history && a.history.pushState && a.addEventListener("popstate", function (a) {
            null !== a.state && Navigator.navigateTo(a.state.target)
        }, !1), a.addEventListener("load", function () {
            function a() {
                setTimeout(function () {
                    n("page.finished", H)
                }, 800)
            }
            B = !0, Navigator.internalLinkEventListener(), ScrollEventTracker.monitor(H, {
                scrolledin: p,
                scrolledout: o,
                offsetbottom: "viewport"
            }, !0), ScrollEventTracker.monitor(H, {
                scrolledin: function () {
                    Navigator.isHome() || Menu.close()
                },
                scrolledout: function () {
                    Navigator.isHome() || Menu.footer()
                },
                offsetbottom: function () {
                    return isMobile ? "auto" !== $(F).css("bottom") ? "viewport " + $(F).css("bottom").replace(/[^-\d\.]/g, "") : void 0 : "1px"
                }
            }, !0), ScrollEventTracker.monitor(H, {
                scrolledin: function () {
                    D.addClass("hide-menu"), "projects" === H.id ? D.addClass("dark-bg") : D.removeClass("dark-bg")
                },
                scrolledout: function () {
                    D.removeClass("hide-menu")
                },
                offsetbottom: function () {
                    return isMobile ? "viewport -400" : "viewport"
                }
            }, !0), Navigator.loadJS(a)
        }, !1), a.addEventListener("unload", function () {
            VideoTracker.endTimer(), VideoTracker.timeWatched > 0 && ga("send", "timing", "Video", "time watched", VideoTracker.timeWatched, {
                transport: "beacon"
            })
        }, !1), a.addEventListener("optimizedScroll", function (a) {
            ScrollEventTracker.checkInView(a)
        }, !1), a.addEventListener("optimizedResize", function () {
            if (viewportHeight = a.innerHeight, viewportWidth = a.innerWidth, t(), Menu.currentCube(), !Navigator.isHome()) try {
                a.dispatchEvent(optimizedScroll)
            } catch (b) {
                console.log(b)
            }
        }, !1), a.addEventListener("orientationchange", function () {
            s() ? D.addClass("minimal-ui") : D.removeClass("minimal-ui"), recalculateHeader()
        }, !1), b.addEventListener(L, function () {
            b[K] ? (storedTitleText = b.title, b.title = "This Also", p()) : (b.title = storedTitleText, o())
        }, !1), I.addEventListener("main.video.play", VideoTracker.startTimer, !1), I.addEventListener("main.video.pause", VideoTracker.endTimer, !1), H.addEventListener("click", y, !0)
    }

    function l(a) {
        if (!isMobile) {
            for (i = 0; i < a.length; i++) {
                var b = a[i];
                if (b.hasAttribute("data-alt") && ("trident" === renderingEngine || "edge" === renderingEngine)) {
                    var c = b.getElementsByTagName("source")[0],
                        d = c.src,
                        e = b.getAttribute("data-alt");
                    c.src = d.substring(0, d.lastIndexOf(".")) + e + d.substring(d.lastIndexOf("."))
                }
                ScrollEventTracker.monitor(b, {
                    scrolledin: function () {
                        this.paused && this.play()
                    },
                    scrolledout: function () {
                        this.paused || this.pause()
                    },
                    offsettop: r(b.getAttribute("data-offsettop")) || null,
                    offsetbottom: r(b.getAttribute("data-offsetbottom")) || null
                })
            }
        }
    }

    function m(a) {
        for (var b = 0; b < a.length; b++) {
            var c = a[b],
                d = c.getAttribute("data-colortransition"),
                e = c.getAttribute("data-colortransitiontext") || null,
                f = $(H).css("background-color"),
                g = $(H).css("color");
            ScrollEventTracker.monitor(c, {
                scrolledin: function () {
                    H.hasAttribute("data-bgcolordefault") || (supportsCSSAnimation ? (H.style.backgroundColor = d, H.style.color = e) : $(H).animate({
                        backgroundColor: d,
                        color: e
                    }, 400))
                },
                scrolledout: function () {
                    supportsCSSAnimation ? (H.style.backgroundColor = "", H.style.color = "") : $(H).animate({
                        backgroundColor: f,
                        color: g
                    }, 400)
                },
                offsettop: .5,
                offsetbottom: .8
            })
        }
    }

    function n(a, b, c) {
        var d = c || {},
            e = new CustomEvent(a, {
                detail: d,
                bubbles: !1,
                cancelable: !1
            });
        b.dispatchEvent(e)
    }

    function o() {
        if (I.setAttribute("data-playstate", "playing"), VideoTracker.startTimer(), isMobile) try {
            TA_VideoLoop.queue[TA_VideoLoop.queuePos].play()
        } catch (a) {
            return
        } else J.play();
        n("main.video.play", I)
    }

    function p() {
        if (I.setAttribute("data-playstate", "paused"), VideoTracker.endTimer(), isMobile) try {
            TA_VideoLoop.queue[TA_VideoLoop.queuePos].stop(), TA_VideoLoop.advanceQueue()
        } catch (a) {
            return
        } else J.pause();
        n("main.video.pause", I)
    }

    function q(a) {
        var b = new XMLHttpRequest;
        return b.open("HEAD", "/ta/static/" + a, !1), b.send(), "true" === b.getResponseHeader("TA-Resource-Found") ? !0 : !1
    }

    function r(a) {
        return a ? /^(\-|\+)?([0-9]+(\.[0-9]+)?|Infinity)$/.test(a) ? Number(a) : a : null
    }

    function s() {
        return isMobile && "webkit" === renderingEngine && !navigator.userAgent.match("CriOS") && 90 !== Math.abs(a.orientation)
    }

    function t() {
        var c = b.fullScreen || b.mozFullScreen || b.webkitIsFullScreen || a.innerWidth === screen.width && a.innerHeight === screen.height;
        c ? D.setAttribute("data-fullscreen", "true") : D.setAttribute("data-fullscreen", "false")
    }

    function u(a) {
        for (var a = a || b, c = a.getElementsByTagName("p"), d = 0; d < c.length; d++) {
            var e = c[d],
                f = e.innerHTML;
            e.innerHTML = f.replace(/\s([^\s<]{0,10})\s*$/, "&nbsp;$1")
        }
    }

    function v() {
        return location.origin + location.pathname
    }

    function w() {
        var a = !1,
            d = "animation",
            e = "",
            f = "Webkit Moz O ms Khtml".split(" "),
            g = "",
            h = b.createElement("div");
        if (h.style.animationName !== c && (a = !0), a === !1)
            for (var i = 0; i < f.length; i++)
                if (h.style[f[i] + "AnimationName"] !== c) {
                    g = f[i], d = g + "Animation", e = "-" + g.toLowerCase() + "-", a = !0;
                    break
                }
        return a
    }

    function x() {
        return b.implementation.hasFeature("http://www.w3.org/TR/SVG11/animate.html#AnimateElement", "1.0")
    }

    function y(a) {
        for (var b = a.target; b !== this;) {
            if (b.hasAttribute("data-gaevent")) {
                var c = JSON.parse(b.getAttribute("data-gaevent"));
                "true" === b.getAttribute("data-gatoggle") && b.removeAttribute("data-gaevent"), ga("send", "event", c.category, c.action, c.label);
                break
            }
            b = b.parentNode
        }
    }

    function z(b, c, d) {
        var d = d || a,
            e = !1,
            f = new CustomEvent(c),
            g = function () {
                e || (e = !0, requestAnimationFrame(function () {
                    d.dispatchEvent(f), e = !1
                }))
            };
        return d.addEventListener(b, g), f
    }

    function A() {
        var a = "┌─────┐\n│ T H │\n│ I S │\n└─────┼─────┐\n      │ A L │\n      │ S O │\n      └─────┘",
            b = "color: #8C1AFF; font-family: monospace;";
        "trident" !== renderingEngine && "edge" !== renderingEngine && setTimeout(console.log.bind(console, "%c" + a, b))
    }
    var B, C, D = b.body,
        E = b.head,
        F = b.getElementById("ta-cube"),
        G = b.getElementById("ta-menu"),
        H = b.getElementsByTagName("main")[0],
        I = b.getElementById("main-video"),
        J = b.getElementById("video");
    $(".menu-link").click(function () {
        C = this.href
    });
    var K, L;
    "undefined" != typeof b.hidden ? (K = "hidden", L = "visibilitychange") : "undefined" != typeof b.mozHidden ? (K = "mozHidden", L = "mozvisibilitychange") : "undefined" != typeof b.msHidden ? (K = "msHidden", L = "msvisibilitychange") : "undefined" != typeof b.webkitHidden && (K = "webkitHidden", L = "webkitvisibilitychange"), "function" != typeof ga && (ga = function (a, b, c, d, e, f) {
        var g = [a || null, b || null, c || null, d || null, e || null, f || null];
        g = g.filter(Boolean)
    }), Menu = {
        init: function () {
            this.navState = D.getAttribute("data-navstate"), this.cubeState = D.getAttribute("data-cubestate"), this.setCurrentPage(v()), this.currentCube(), this.cubeOffsetMax = {
                large: 175,
                small: 145
            }, F.addEventListener(clickEvent, function () {
                "open" === D.getAttribute("data-navstate") ? Menu.close() : Menu.open()
            }, !1), G.addEventListener("touchstart", function (a) {
                var b = a.target;
                if (b.hasClass("menu-link")) {
                    var c = b.className.split(" ");
                    c.push("hover"), b.className = c.join(" ")
                }
            }, !1), G.addEventListener("touchend", function (a) {
                for (var c = b.querySelectorAll(".menu-link"), d = 0; d < c.length; d++) c[d].className = c[d].className.replace(" hover", "")
            }, !1), F.addEventListener("touchstart", function (a) {
                F.addClass("active")
            }, !1), F.addEventListener("touchend", function (a) {
                F.removeClass("active")
            }, !1)
        },
        home: function () {
            "home" !== Menu.navState && (Menu.navState = "home", D.setAttribute("data-navstate", "home"))
        },
        footer: function () {
            if ("footer" !== Menu.navState && (Menu.navState = "footer", D.setAttribute("data-navstate", "footer"), VideoTracker.startTimer(), !supportsSVGAnimation)) {
                $(".container", G).css({
                    bottom: "-60px",
                    position: "absolute"
                }), $(".container", G).animate({
                    bottom: "0px"
                }, 200);
                var a = Menu.cube.getAttribute("data-size");
                Menu.animateRoute(Menu.cube, 0, Menu.cubeOffsetMax[a])
            }
        },
        open: function () {
            "open" !== Menu.navState && (Menu.navState = "open", D.addEventListener("touchmove", Menu.disableScroll, !1), D.setAttribute("data-navstate", "open"))
        },
        close: function () {
            if ("hide" !== Menu.navState && (Menu.navState = "hide", D.removeEventListener("touchmove", Menu.disableScroll), D.setAttribute("data-navstate", "hide"), VideoTracker.endTimer(), !supportsSVGAnimation && "0" !== a.getComputedStyle(Menu.cube).getPropertyValue("stroke-dashoffset"))) {
                var b = Menu.cube.getAttribute("data-size");
                Menu.animateRoute(Menu.cube, Menu.cubeOffsetMax[b], 0)
            }
        },
        load: function () {
            "loading" !== Menu.cubeState && (Menu.cubeState = "loading", D.setAttribute("data-cubestate", "loading"))
        },
        working: function () {
            "working" !== Menu.cubeState && (Menu.cubeState = "working", D.setAttribute("data-cubestate", "working"))
        },
        endload: function () {
            "" !== Menu.cubeState && (Menu.cubeState = "", D.setAttribute("data-cubestate", ""))
        },
        disableScroll: function (a) {
            a.preventDefault()
        },
        setCurrentPage: function (a) {
            var b = /[^/]*$/.exec(a)[0];
            $("li", G).removeClass("active"), b && $("li[data-pageid=" + b + "]", G).addClass("active")
        },
        animateRoute: function (a, b, c) {
            b > c ? (b -= 10, c >= b && (b = c)) : c > b && (b += 10, b >= c && (b = c)), a.style.strokeDashoffset = b, b !== c && setTimeout(function () {
                Menu.animateRoute(a, b, c)
            }, 10)
        },
        currentCube: function () {
            $("svg path").each(function () {
                return "block" == $(this).css("display") ? void(Menu.cube = this) : void 0
            })
        }
    }, Navigator = {
        pageID: H.id,
        tracking: location.search,
        hash: location.hash && location.hash.substring(1),
        init: function () {
            function d() {
                g(), h()
            }

            function e() {
                i(), f()
            }

            function f() {
                Navigator.helper.ready() && n("page.display", H)
            }

            function g() {
                D.addClass("page-out"), H.style.backgroundColor = "", H.style.color = "", "projects" === H.id ? D.addClass("dark-bg") : D.removeClass("dark-bg"), setTimeout(function () {
                    Navigator.helper.hidden(), n("page.hidden", H)
                }, Navigator.helper.leaveTiming())
            }

            function h() {
                var a = Navigator.helper.response.getElementsByTagName("main")[0];
                u(a), Navigator.helper.content = a.innerHTML, Navigator.helper.className = a.className, Navigator.pageID = a.id, Navigator.helper.isPush() && Navigator.helper.href !== c ? history.pushState({
                    target: Navigator.helper.href
                }, Navigator.helper.title, Navigator.helper.href) : Navigator.helper.isPush() && Navigator.helper.href === c && ("projects" === H.id ? (history.pushState({
                    target: Navigator.helper.href
                }, Navigator.helper.title, "projects/" + Navigator.pageID), console.log(Navigator.pageID)) : (history.pushState({
                    target: Navigator.helper.href
                }, Navigator.helper.title, C), console.log(C))), Navigator.isHome() && Menu.home(), Navigator.helper.loaded(), n("page.loaded", H)
            }

            function i() {
                Navigator.unloadJS(), H.innerHTML = "";
                var c = new RegExp("#(.*)[?/]?"),
                    d = c.exec(Navigator.helper.href);
                if (null !== d) {
                    var e = b.getElementById(d[1]),
                        f = e.getBoundingClientRect().top,
                        g = f + b.body.scrollTop;
                    a.scroll(0, g)
                } else a.scroll(0, 0)
            }

            function j() {
                H.innerHTML = Navigator.helper.content, H.id = Navigator.helper.id(), H.className = Navigator.helper.className, b.title = Navigator.helper.title, Navigator.setStylesheet(), Navigator.loadJS(), Menu.setCurrentPage(Navigator.helper.href);
                try {
                    a.dispatchEvent(optimizedScroll)
                } catch (c) {
                    console.log(c)
                }
                D.removeClass("page-out"), "projects" !== H.id && D.removeClass("dark-bg"), Navigator.trackPage(Navigator.helper.href + Navigator.tracking, Navigator.helper.title), Navigator.isHome() && VideoTracker.startTimer(), setTimeout(function () {
                    n("page.finished", H)
                }, Navigator.helper.enterTiming())
            }

            function k() {
                Menu.endload(), H.removeClass("no-animation"), delete Navigator.helper
            }
            if (a.history && a.history.pushState) {
                var l = v() + Navigator.tracking;
                history.replaceState({
                    target: location.href
                }, null, l), $(b).keydown(function (a) {
                    (a.shiftKey || a.ctrlKey || a.metaKey) && (Navigator.cntrPressed = !0)
                }), $(b).keyup(function () {
                    Navigator.cntrPressed = !1
                })
            }
            H.addEventListener("page.setup", d, !1), H.addEventListener("page.hidden", e, !1), H.addEventListener("page.loaded", f, !1), H.addEventListener("page.display", j, !1), H.addEventListener("page.finished", k, !1)
        },
        navigateTo: function (b, c) {
            function d() {
                var a = new XMLHttpRequest;
                a.addEventListener("readystatechange", function () {
                    a.readyState === XMLHttpRequest.DONE && (200 === a.status ? (Navigator.helper = new Navigator.Helper(a, h), n("page.setup", H)) : 404 === a.status ? f() : g())
                }, !1), a.open("GET", b, !0), a.responseType = "document", a.send()
            }

            function e() {
                Menu.endload()
            }

            function f() {
                a.location.href = b, ga("send", "exception", {
                    exDescription: "XHR status = 400: Could not load page.",
                    exFatal: !1
                }), n("page.finished", H)
            }

            function g() {
                console.error("Client side issue. Sorry. It's not you, it's us."), ga("send", "exception", {
                    exDescription: "XHR status = " + Navigator.helper.status + ": Could not load page.",
                    exFatal: !1
                }), n("page.finished", H)
            }
            var h = c && b !== v();
            return "footer" === Menu.navState && h === !1 ? void $("html, body").scrollTop("0") : (Menu.close(), Navigator.isHome(b) ? o() : (Menu.load(), p()), void(h !== !1 ? d() : e()))
        },
        isHome: function (a) {
            var b = a || v();
            return b === baseURL
        },
        internalLinkEventListener: function () {
            G.addEventListener(clickEndEvent, function (a) {
                dragging && a.preventDefault()
            }, !1), D.addEventListener(clickEndEvent, function (b) {
                "A" === b.target.tagName && (Navigator.cntrPressed || (b.target.href.indexOf(baseURL) >= 0 && a.history && a.history.pushState && b.target.href !== baseURL && (b.preventDefault(), Navigator.navigateTo(b.target.href, !0)), "footer" !== Menu.navState && "home" !== Menu.navState && Menu.close()))
            }, !1)
        },
        trackPage: function (a, b) {
            ga("send", {
                hitType: "pageview",
                location: a,
                title: b
            })
        },
        setStylesheet: function () {
            var a = $("link[data-pageid]");
            $(a).each(function () {
                $(this).prop("disabled", !0)
            });
            var b = $("link[data-pageid=" + Navigator.pageID + "]");
            if (b.length > 0) $(b).prop("disabled", !1);
            else if (q("styles/projects/" + Navigator.pageID + ".css")) {
                var c = '<link data-pageid="' + Navigator.pageID + '" rel="stylesheet" href="/styles/projects/' + Navigator.pageID + '.css">';
                $(E).append(c)
            }
        },
        loadJS: function (a) {
            var c = Navigator.helper && Navigator.helper.id() || Navigator.pageID,
                d = b.getElementsByClassName("ta-video"),
                e = Pages["default"];
            if (!isMobile) var f = Array.prototype.slice.call(b.querySelectorAll("[data-colortransition]"));
            d.length > 0 && l(d), !isMobile && f.length > 0 && m(f), Pages[c] && (e = Pages[c]), $.getMultiScripts(e.scripts).done(e.load), ScrollEventTracker.setNodes(), "function" == typeof a && a()
        },
        unloadJS: function () {
            ScrollEventTracker.unloadNodes(), Pages[Navigator.helper.id()] ? Pages[Navigator.helper.id()].unload() : Pages["default"].unload()
        },
        Helper: function (a, b) {
            var c = !1,
                d = !1,
                e = 800,
                f = 600,
                g = 200,
                b = b;
            this.href = a.responseURL, this.response = a.response, this.status = a.status, this.title = a.response.title, this.content = "", this.className = "", this.isPush = function () {
                return b
            }, this.id = function () {
                return Navigator.pageID
            }, this.leaveTiming = function () {
                return Navigator.isHome() ? 0 : e + g
            }, this.enterTiming = function () {
                return f + g
            }, this.loaded = function () {
                c = !0
            }, this.hidden = function () {
                d = !0
            }, this.ready = function () {
                return c && d
            }
        }
    }, ScrollEventTracker = {
        permaNodes: [],
        nodes: [],
        monitor: function (a, b, c) {
            var d = {
                element: a,
                options: b,
                visible: !1
            };
            return c ? ScrollEventTracker.permaNodes.push(d) : ScrollEventTracker.nodes.push(d), d
        },
        isInView: function (a) {
            function c(a) {
                return "function" == typeof a && (a = a()), a ? "viewport" === a ? viewportHeight : "string" == typeof a && a.indexOf("viewport") > -1 ? viewportHeight - a.replace("viewport ", "") : "string" == typeof a ? a.replace("px", "") : "number" == typeof a ? a * viewportHeight : void 0 : 0
            }
            var d = a.element,
                e = b.documentElement && b.documentElement.scrollTop || b.body.scrollTop,
                f = e + viewportHeight,
                g = $(d).offset().top,
                h = g + d.offsetHeight,
                i = c(a.options.offsettop),
                j = c(a.options.offsetbottom);
            return f - i >= g && h - j >= e
        },
        checkInView: function (a) {
            for (var b = 0; b < ScrollEventTracker.nodes.length; b++) {
                var c = ScrollEventTracker.nodes[b];
                ScrollEventTracker.isInView(c) ? c.visible || (c.visible = !0, c.options.scrolledin && c.options.scrolledin.call(c.element, a)) : c.visible && (c.visible = !1, c.options.scrolledout && c.options.scrolledout.call(c.element, a))
            }
        },
        unloadNodes: function () {
            ScrollEventTracker.nodes = []
        },
        setNodes: function () {
            ScrollEventTracker.nodes = ScrollEventTracker.nodes.concat(ScrollEventTracker.permaNodes)
        }
    }, VideoTracker = {
        timeStart: null,
        timeWatched: 0,
        tracking: !1,
        startTimer: function () {
            VideoTracker.tracking || (VideoTracker.tracking = !0, VideoTracker.timeStart = (new Date).getTime())
        },
        endTimer: function () {
            if (VideoTracker.tracking) {
                VideoTracker.tracking = !1;
                var a = (new Date).getTime(),
                    b = a - VideoTracker.timeStart;
                VideoTracker.timeWatched += b
            }
        }
    }, Pages = {}, Pages.studio = {
        scripts: ["/js/libraries/paper.js"],
        load: function () {
            isMobile || (this.liquid = b.createElement("script"), this.liquid.setAttribute("canvas", "blob"), this.liquid.type = "text/paperscript", this.liquid.src = "/js/modules/liquid.js", $("#blob-container").append(this.liquid))
        },
        unload: function () {
            delete this.paper, delete this.liquid
        }
    }, Pages.careers = {
        scripts: [],
        load: function () {
            this.accordion = new d(".accordion")
        },
        unload: function () {
            delete this.accordion
        }
    }, Pages.contact = {
        scripts: ["//maps.googleapis.com/maps/api/js?key=AIzaSyC-cZDqXVNSHdnPzCH1UECAr5Z-HQUh4DI"],
        load: function () {
            isMobile || (this.map = new e)
        },
        unload: function () {
            isMobile || delete this.map
        }
    }, Pages.projects = {
        scripts: [],
        load: function () {
            D.addClass("dark-bg")
        },
        unload: function () {
            D.removeClass("dark-bg")
        }
    }, Pages["chromecast-big-web-quiz"] = {
        scripts: ["/js/libraries/slick.js"],
        load: function () {
            this.carousel = new f(".carousel"), this.carousel.init(), this.video = new g("bwq-video"), this.video.init(), D.removeClass("dark-bg")
        },
        unload: function () {
            delete this.carousel, delete this.video
        }
    }, Pages["ray-super-remote"] = {
        scripts: [],
        load: function () {
            this.windows = new j("ray-sandbox"), this.windows.init(), D.removeClass("dark-bg")
        },
        unload: function () {
            delete this.windows
        }
    }, Pages.sprayscape = {
        scripts: ["/js/libraries/three.min.js", "/js/libraries/photo-sphere-viewer.min.js"],
        load: function () {
            D.removeClass("dark-bg"), isMobile || "edge" === renderingEngine || (this.sprayscape = b.createElement("script"), this.sprayscape.src = "/js/modules/sprayscape.js", $("#spray").append(this.sprayscape))
        },
        unload: function () {
            delete this.sprayscape
        }
    }, Pages["project-ara"] = {
        scripts: [],
        load: function () {
            D.removeClass("dark-bg")
        },
        unload: function () {}
    }, Pages.ooo = {
        scripts: [],
        load: function () {
            this.windows = new j("process"), this.windows.init(), this.soundcloud3 = new h("sound3"), this.soundcloud3.init(), this.soundcloud4 = new h("sound4"), this.soundcloud4.init(), this.soundcloud5 = new h("sound5"), this.soundcloud5.init(), this.soundcloud6 = new h("sound6"), this.soundcloud6.init(), D.removeClass("dark-bg")
        },
        unload: function () {
            delete this.windows, delete this.soundcloud3, delete this.soundcloud4, delete this.soundcloud5, delete this.soundcloud6
        }
    }, Pages["real-nyc-stickers"] = {
        scripts: [],
        load: function () {
            this.video = new g("real-nyc-video"), this.video.init(), D.removeClass("dark-bg")
        },
        unload: function () {
            delete this.video
        }
    }, Pages["default"] = {
        scripts: [],
        load: function () {},
        unload: function () {}
    }, k()
}(window, document), Array.prototype.remove = function () {
    for (var a, b, c = arguments, d = c.length; d && this.length;)
        for (a = c[--d]; - 1 !== (b = this.indexOf(a));) this.splice(b, 1);
    return this
}, Element.prototype.hasClass = function (a) {
    return this.className && new RegExp("(^|\\s)" + a + "(\\s|$)").test(this.className)
}, Element.prototype.addClass = function (a) {
    return this.hasClass(a) ? void 0 : (this.className += " " + a, !0)
}, Element.prototype.removeClass = function (a) {
    var b = new RegExp("(^|\\s)" + a + "(\\s|$)");
    return this.className = this.className.replace(b, " "), !0
}, $.getMultiScripts = function (a) {
    var b = $.map(a, function (a) {
        return $.getScript(a)
    });
    return b.push($.Deferred(function (a) {
        $(a.resolve)
    })), $.when.apply($, b)
};
