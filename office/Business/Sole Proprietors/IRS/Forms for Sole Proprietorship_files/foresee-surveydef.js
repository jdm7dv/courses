(function(){

    var FSR;

    // Do we support AMD?
    var supports_amd =
        typeof(window.define) === 'function' && window.define.amd &&
            (!window.FSR || window.FSR.supportsAMD);

    if(!supports_amd)
        FSR = window.FSR;
    else
        FSR = {};

    FSR.surveydefs = [{
    name: 'browse',
    section: 'directpay',
    platform: 'desktop',
    repeatdays: 60,
    invite: {
        when: 'onentry',
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting IRS Direct Pay. You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            noticeAboutSurvey: "The survey is designed to measure your entire experience, please look for it at the <u>conclusion</u> of your visit.",
            attribution: "This survey is conducted by an independent company ForeSee, on behalf of the site you are visiting.",
            closeInviteButtonText: "Click to close.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll give feedback",
            error: "Error",
            warnLaunch: "this will launch a new window"
        }]],
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov/directpay/payment(?!(.)*execution=e1s1(.)*)', 'directpay.irs.gov/directpay/paymentManager(?!(.)*execution=e1s1(.)*)']
        }
    },
    pop: {
        when: 'later'
    },
    tracker: {
        url: 'tracker_directpay.html'
    },
    criteria: {
        sp: [50, 50],
        lf: 1
    },
    include: {
        urls: ['execution=e1s1']
    }
}, {
    name: 'mobile_web',
    section: 'directpay',
    platform: 'phone',
    repeatdays: 90,
    invite: {
        when: 'onentry',
        // Mobile
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting IRS Direct Pay.  You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            attribution: "Conducted by ForeSee.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll help",
            error: "Error",
            warnLaunch: "this will launch a new window"
        }]],
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov/directpay/payment(?!(.)*execution=e1s1(.)*)', 'directpay.irs.gov/directpay/paymentManager(?!(.)*execution=e1s1(.)*)']
        }
    },
    pop: {
        when: 'now'
    },
    criteria: {
        sp: [50, 50],
        lf: 1
    },
    include: {
        urls: ['execution=e1s1']
    }
}, {
    name: 'tablet_web',
    section: 'directpay',
    platform: 'tablet',
    repeatdays: 90,
    invite: {
        when: 'onentry',
        // Mobile
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting IRS Direct Pay.  You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            attribution: "Conducted by ForeSee.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll help",
            error: "Error",
            warnLaunch: "this will launch a new window"
        }]],
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov/directpay/payment(?!(.)*execution=e1s1(.)*)', 'directpay.irs.gov/directpay/paymentManager(?!(.)*execution=e1s1(.)*)']
        }
    },
    pop: {
        when: 'now'
    },
    criteria: {
        sp: [50, 50],
        lf: 1
    },
    include: {
        urls: [/\/directpay\/payment\?execution=e1s1/g, /\/directpay\/paymentManager\?execution=e1s1/g, /\/directpay\/payment\?execution=e2s1/g, /\/directpay\/paymentManager\?execution=e2s1/g, /\/directpay\/payment\?execution=e3s1/g, /\/directpay\/paymentManager\?execution=e3s1/g, /\/directpay\/payment\?execution=e4s1/g, /\/directpay\/paymentManager\?execution=e4s1/g, /\/directpay\/payment\?execution=e5s1/g, /\/directpay\/paymentManager\?execution=e5s1/g, /\/directpay\/payment\?execution=e6s1/g, /\/directpay\/paymentManager\?execution=e6s1/g, /\/directpay\/payment\?execution=e7s1/g, /\/directpay\/paymentManager\?execution=e7s1/g, /\/directpay\/payment\?execution=e8s1/g, /\/directpay\/paymentManager\?execution=e8s1/g]
    }
}, {
    name: 'browse',
    section: 'aca_emp',
    repeatdays: 0,
    platform: 'desktop',
    invite: {
        when: 'onentry',
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting <b style='font-weight:bold'>Affordable Care Act (ACA) Tax Provisions</b> section of the IRS.gov website. You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            noticeAboutSurvey: "The survey is designed to measure your entire experience, please look for it at the <u>conclusion</u> of your visit.",
            attribution: "This survey is conducted by an independent company ForeSee, on behalf of the site you are visiting.",
            closeInviteButtonText: "Click to close.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll give feedback",
            error: "Error",
            warnLaunch: "this will launch a new window"
        }]],
        delay: 20,
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov']
        }
    },
    pop: {
        when: 'later',
        what: 'qualifier'
    },
    tracker: {
        url: 'tracker_aca.html'
    },
    qualifier: {
        url: 'qualifying_aca.html'
    },
    criteria: {
        sp: [100, 100],
        lf: 1
    },
    include: {
        urls: ['irs.gov/Affordable-Care-Act/Employers', 'irs.gov/Affordable-Care-Act/Employers/Employer-Shared-Responsibility-Provisions', 'irs.gov/Affordable-Care-Act/Employers/Information-Reporting-by-Applicable-Large-Employers', 'irs.gov/Affordable-Care-Act/Questions-and-Answers-on-Information-Reporting-by-Health-Coverage-Providers-Section-6055', 'irs.gov/Affordable-Care-Act/Employers/Questions-and-Answers-about-Employer-Information-Reporting-on-Form-1094-C-and-Form-1095-C', 'irs.gov/Affordable-Care-Act/Employers/Affordable-Care-Act-Tax-Provisions-for-Large-Employers', 'irs.gov/Affordable-Care-Act/Employers/Questions-and-Answers-on-Reporting-of-Offers-of-Health-Insurance-Coverage-by-Employers-Section-6056']
    }
}, {
    name: 'browse',
    section: 'aca',
    repeatdays: 0,
    platform: 'desktop',
    invite: {
        when: 'onentry',
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting <b style='font-weight:bold'>Affordable Care Act (ACA) Tax Provisions</b> section of the IRS.gov website. You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            noticeAboutSurvey: "The survey is designed to measure your entire experience, please look for it at the <u>conclusion</u> of your visit.",
            attribution: "This survey is conducted by an independent company ForeSee, on behalf of the site you are visiting.",
            closeInviteButtonText: "Click to close.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll give feedback",
            error: "Error",
            warnLaunch: "this will launch a new window"
        }]],
        delay: 20,
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov']
        }
    },
    pop: {
        when: 'later'
    },
    tracker: {
        url: 'tracker_aca.html'
    },
    criteria: {
        sp: [100, 100],
        lf: 1
    },
    include: {
        urls: ['irs.gov/Affordable-Care-Act', 'irs.gov/Affordable-Care-Act/Individuals-and-Families', 'irs.gov/Affordable-Care-Act/Individuals-and-Families/The-Premium-Tax-Credit', 'irs.gov/Affordable-Care-Act/Individuals-and-Families/Individual-Shared-Responsibility-Provision']
    }
}, {
    name: 'browse',
    section: 'main',
    repeatdays: 0,
    platform: 'desktop',
    invite: {
        when: 'onentry',
        exclude: {
            urls: ['/irspup', 'directpay.irs.gov']
        }
    },
    pop: {
        when: 'later'
    },
    criteria: {
        sp: [0, 5],
        lf: 3,
        locales: [{
            locale: 'es',
            sp: [0, 100],
            lf: 3
        }]
    },
    include: {
        urls: ['.']
    }
}];
FSR.properties = {
    //repeatdays : 90,
    
    repeatoverride: false,
    
    altcookie: {},
    
    language: {
        locale: 'en',
        src: 'location',
        locales: [{
            match: /Spanish/i,
            locale: 'es'
        }]
    },
    
    exclude: {},
    /* Invite branding sample property
     brands : [{"c":"Foresee","p":33}, {"c":"Answers", "p":33}, {"c":"ForeseeByAnswers", "p":33}],
     */
    zIndexPopup: 10000,
    
    ignoreWindowTopCheck: false,
    
    ipexclude: 'fsr$ip',
    
    mobileHeartbeat: {
        delay: 60, /*mobile on exit heartbeat delay seconds*/
        max: 3600 /*mobile on exit heartbeat max run time seconds*/
    },
    
    invite: {
    
        // For no site logo, comment this line:
        siteLogo: "sitelogo.gif",
        
        //alt text fore site logo img
        siteLogoAlt: "",
        
        /* Desktop */
        dialogs: [[{
            reverseButtons: false,
            headline: "We'd welcome your feedback!",
            blurb: "Thank you for visiting our website. You have been selected to participate in a brief customer satisfaction survey to let us know how we can improve your experience.",
            noticeAboutSurvey: "The survey is designed to measure your entire experience, please look for it at the <u>conclusion</u> of your visit.",
            attribution: "This survey is conducted by an independent company ForeSee, on behalf of the site you are visiting.",
            closeInviteButtonText: "Click to close.",
            declineButton: "No, thanks",
            acceptButton: "Yes, I'll give feedback",
            error: "Error",
            warnLaunch: "this will launch a new window",
            
            locales: {
                "es": {
                    headline: "¡Le agradecemos sus opiniones y comentarios!",
                    blurb: "Le agrademos su visita al sitio web del IRS. Usted ha sido elegido(a) para participar en una breve encuesta de satisfacción del cliente para informarnos acerca de cómo podemos mejorar su experiencia.",
                    noticeAboutSurvey: "La encuesta está diseñada para medir toda su experiencia con nosotros, sírvase buscarla al <u>finalizar</u> su visita.",
                    attribution: "Esta encuesta se realiza a través de una empresa independiente, ForeSee, en nombre del sitio que usted está visitando.",
                    closeInviteButtonText: "Haga clic para cerrar.",
                    declineButton: "No, gracias",
                    acceptButton: "Sí, deseo dar mi opinión",
                    error: "Error",
                    warnLaunch: "this will launch a new window"
                }
            }
        
        }]],
        
        exclude: {
            urls: [],
            referrers: [],
            userAgents: [],
            browsers: [],
            cookies: [],
            variables: []
            // [name (content), http-equiv (content), itemprop (content),  charset] possible attributes for meta tag element http://devdocs.io/html/meta
            // metas:[{"name":{"key":"value", "content":"value"}}, {"http-equiv":{"key":"value", "content":"value"}}, {"itemprop":{"key":"value", "content":"value"}}, {"charset":{"key":"value"}}]
        
        },
        include: {
            local: ['.']
        },
        
        delay: 0,
        timeout: 0,
        
        hideOnClick: false,
        
        hideCloseButton: false,
        
        css: 'foresee-dhtml.css',
        
        hide: [],
        
        hideFlash: false,
        
        type: 'dhtml',
        /* desktop */
        // url: 'invite.html'
        /* mobile */
        url: 'invite-mobile.html',
        back: 'url'
    
        //SurveyMutex: 'SurveyMutex'
    },
    
    tracker: {
        width: '690',
        height: '415',
        timeout: 3,
        //pu: false,
        adjust: true,
        alert: {
            enabled: true,
            message: 'The survey is now available.',
            locales: [{
                locale: 'es',
                message: 'Su encuesta ya está disponible.'
            }]
        },
        url: 'tracker.html',
        locales: [{
            locale: 'es',
            url: 'tracker_es.html'
        }]
    },
    
    survey: {
        width: 690,
        height: 600
    },
    
    qualifier: {
        footer: '<div id=\"fsrcontainer\"><div style=\"float:left;width:80%;font-size:8pt;text-align:left;line-height:12px;\">This survey is conducted by an independent company ForeSee,<br>on behalf of the site you are visiting.</div><div style=\"float:right;font-size:8pt;\"><a target="_blank" title="Validate TRUSTe privacy certification" href="//privacy-policy.truste.com/click-with-confidence/ctv/en/www.foreseeresults.com/seal_m"><img border=\"0\" src=\"{%baseHref%}truste.png\" alt=\"Validate TRUSTe Privacy Certification\"></a></div></div>',
        width: '690',
        height: '500',
        bgcolor: '#333',
        opacity: 0.7,
        x: 'center',
        y: 'center',
        delay: 0,
        buttons: {
            accept: 'Continue'
        },
        hideOnClick: false,
        css: 'foresee-dhtml.css',
        url: 'qualifying.html'
    },
    
    cancel: {
        url: 'cancel.html',
        width: '690',
        height: '400'
    },
    
    pop: {
        what: 'survey',
        after: 'leaving-site',
        pu: false,
        tracker: true
    },
    
    meta: {
        referrer: true,
        terms: true,
        ref_url: true,
        url: true,
        url_params: false,
        user_agent: false,
        entry: false,
        entry_params: false,
        viewport_size: false,
        document_size: false,
        scroll_from_top: false,
        invite_URL: false
    },
    
    events: {
        enabled: true,
        id: true,
        codes: {
            purchase: 800,
            items: 801,
            dollars: 802,
            followup: 803,
            information: 804,
            content: 805
        },
        pd: 7,
        custom: {}
    },
    
    previous: false,
    
    analytics: {
        google_local: false,
        google_remote: false
    },
    
    cpps: {},
    
    mode: 'first-party'
};


    if(supports_amd)
        define(function(){ return FSR; })
})();
