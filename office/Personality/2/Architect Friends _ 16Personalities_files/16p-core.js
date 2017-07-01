var $j = jQuery.noConflict();
var inProgress = false;
var resultsSent = false;
var windowWidth = $j(window).width();

$j(document).ready(function() {

    $j(window).resize(function () {

        if ($j(window).width() != windowWidth) {

            windowWidth = $j(window).width();

            if ($j('#mobile-navigation').is(':visible')) {
                $j('#mobile-menu-switch').click();
            }

        }

    });

});

// Mobile menus

$j('#mobile-menu-switch').click(function () {

    if (!$j('#mobile-navigation').is(':visible')) {

        if ($j('.profile-menu-wrapper').length == 1) {
            var navOffset = $j('.navigation').height() + 25;
        } else {
            var navOffset = $j('.navigation').height() + 26;
        }

        $j('#mobile-navigation')
            .css('top', navOffset)
            .css('height', $j(window).height() - navOffset);
        $j('body').css('overflow', 'hidden');

    } else {

        $j('body').css('overflow', 'auto');

    }

    $j('#mobile-menu-switch').toggleClass('active');
    $j('.navbar').toggleClass('menu-mode');
    $j('#mobile-navigation').toggle();

});

$j('#mobile-navigation .menu-item.description-list').click(function () {

    if (!$j('#mobile-navigation .type-sections').is(':visible')) {
        $j('#mobile-navigation .menu-item.description-list .fa').switchClass('fa-caret-right', 'fa-caret-down', 0);
    } else {
        $j('#mobile-navigation .menu-item.description-list .fa').switchClass('fa-caret-down', 'fa-caret-right', 0);
    }

    $j('#mobile-navigation .type-sections').slideToggle();

});

$j('#mobile-navigation .menu-item.members-area-list').click(function () {

    if (!$j('#mobile-navigation .members-area-sections').is(':visible')) {
        $j('#mobile-navigation .menu-item.members-area-list .fa').switchClass('fa-caret-right', 'fa-caret-down', 0);
    } else {
        $j('#mobile-navigation .menu-item.members-area-list .fa').switchClass('fa-caret-down', 'fa-caret-right', 0);
    }

    $j('#mobile-navigation .members-area-sections').slideToggle();

});

$j('#mobile-navigation .profile-link-wrapper span.fa-share-alt').click(function () {
    $j('#mobile-navigation .profile-link-wrapper .profile-link').focus();
});

$j(document).on('click', '.share-link', function () {

    var network = $j(this).data('network');
    var pageFull = window.location.pathname;
    var page = pageFull.substr(pageFull.lastIndexOf('/') + 1);

    if (page == 'free-personality-test' || page == 'test-results' || $j('.type-header-results').css('display') == 'block') {
        page = 'personality-test';
    } else if (pageFull.indexOf('country-profiles') > 0) {
        page = pageFull;
    }

    var dataString = 'network=' + network + '&page=' + page + '&_token=' + $j('#_token').val();
    var jqxhr = $j.post('/social-stats/add', dataString);

});

$j('#comment-tabs #comments-facebook').click(function (e) {
    FB.XFBML.parse();
});

$j(document).on('click', '#profile-menu-toggle', function () {
    $j('#profile-menu').toggle();
});

$j(document).click(function(event) {

    if (!$j(event.target).closest('#profile-menu-toggle').length) {

        if (!$j(event.target).closest('#profile-menu').length) {
            $j('#profile-menu').hide();
        }

    }

});

$j(document).on('click', '#profile-menu .profile-switch', function () {

    $j('#profile-menu .notifications-tab, #profile-menu .updates-tab').hide();
    $j('#profile-menu .profile-tab').show();

    $j('#profile-menu .notifications-switch, #profile-menu .updates-switch').removeClass('active');
    $j('#profile-menu .profile-switch').addClass('active');

});

$j(document).on('click', '#profile-menu .notifications-switch', function () {

    $j('#profile-menu .profile-tab, #profile-menu .updates-tab').hide();
    $j('#profile-menu .notifications-tab').show();
    $j('#profile-menu .profile-switch, #profile-menu .updates-switch').removeClass('active');
    $j('#profile-menu .notifications-switch').addClass('active');

    $j('#profile-menu .notifications-tab').html('<div class="placeholder"><span class="fa fa-spin fa-spinner"></span></div>');

    var jqxhr = $j.get('/users/fetch-notifications', function (data) {

        if (data.code == 200) {

            $j('#profile-menu .notifications-tab').html('');

            if (data.notifications.length > 0) {

                var toAppend = '<div class="alert-list">';

                $j.each(data.notifications, function (index, notification) {

                    toAppend += '<a href="' + notification.link + '" class="row alert-item' + notification.flags + '">';
                    toAppend += '<div class="col-xs-10 description">';
                    toAppend += notification.text;
                    toAppend += '<div class="timestamp">' + notification.timestamp + '</div></div>';
                    toAppend += '<div class="col-xs-2 icon"><span class="fa fa-caret-right"></span></div></a>';

                });

                toAppend += '</div>';
                toAppend += '<div class="row alert-bottom"><a href="/users/notifications">See all notifications</a></div>';

                $j('#profile-menu .notifications-tab').append(toAppend);

            } else {

                $j('#profile-menu .notifications-tab').append('<div class="row alert-bottom empty">No recent notifications.</div>');

            }

            $j('#profile-menu .notifications-switch').data('count', 0);
            var remainingNotifications = $j('#profile-menu .updates-switch').data('count');

            $j('.navbar-static-top .toggle-badge').html(remainingNotifications);

            if (remainingNotifications == 0) {

                $j('.navbar-static-top .toggle-badge').removeClass('has-unread');
                $j('.navbar-static-top #profile-menu .switches .notifications-switch .badge').removeClass('has-notifications');

            }

        } else {

            alert(data.message);
            $j('#profile-menu .profile-switch').trigger('click');

        }

    })
    .fail(function () {

        alert('Apologies, we could not connect to our server. Please try again later.');
        $j('#profile-menu .profile-switch').trigger('click');

    })

});

$j(document).on('click', '#profile-menu .updates-switch', function () {

    $j('#profile-menu .profile-tab, #profile-menu .notifications-tab').hide();
    $j('#profile-menu .updates-tab').show();
    $j('#profile-menu .profile-switch, #profile-menu .notifications-switch').removeClass('active');
    $j('#profile-menu .updates-switch').addClass('active');

    $j('#profile-menu .updates-tab').html('<div class="placeholder"><span class="fa fa-spin fa-spinner"></span></div>');

    var jqxhr = $j.get('/users/fetch-updates', function (data) {

        if (data.code == 200) {

            $j('#profile-menu .updates-tab').html('');

            if (data.updates.length > 0) {

                var toAppend = '<div class="alert-list">';

                $j.each(data.updates, function (index, update) {

                    toAppend += '<a href="' + update.link + '" class="row alert-item seen">';
                    toAppend += '<div class="col-xs-10 description">';
                    toAppend += update.text;
                    toAppend += '<div class="timestamp">' + update.timestamp + '</div></div>';
                    toAppend += '<div class="col-xs-2 icon"><span class="fa fa-caret-right"></span></div></a>';

                });

                toAppend += '</div>';
                toAppend += '<div class="row alert-bottom"><a href="/users/updates">See all updates</a></div>';

                $j('#profile-menu .updates-tab').append(toAppend);

            } else {

                $j('#profile-menu .updates-tab').append('<div class="row alert-bottom empty">No recent updates.</div>');

            }

            $j('#profile-menu .updates-switch').data('count', 0);
            var remainingNotifications = $j('#profile-menu .notifications-switch').data('count');

            $j('.navbar-static-top .toggle-badge').html(remainingNotifications);

            if (remainingNotifications == 0) {

                $j('.navbar-static-top .toggle-badge').removeClass('has-unread');
                $j('.navbar-static-top #profile-menu .switches .updates-switch .badge').removeClass('has-notifications');

            }

        } else {

            alert(data.message);
            $j('#profile-menu .profile-switch').trigger('click');

        }

    })
        .fail(function () {

            alert('Apologies, we could not connect to our server. Please try again later.');
            $j('#profile-menu .profile-switch').trigger('click');

        })

});

$j(document).on('click', '#profile-menu-request-submit', function () {

    if (inProgress || resultsSent) return;

    $j('#profile-menu .primary-wrapper .request-wrapper .alert-wrapper').hide();
    $j('#profile-menu-request-email').removeClass('invalid');

    var email = $j('#profile-menu-request-email').val();
    var etapos = email.indexOf('@');
    var dotpos = email.lastIndexOf('.');

    if (email == '' || etapos < 1 || dotpos < etapos + 2 || dotpos + 2 >= email.length) {
        $j('#profile-menu-request-email').addClass('invalid');
        return false;
    }

    inProgress = true;

    $j('#profile-menu-request-submit').switchClass('btn-action-2', 'btn-default', 0).css('cursor', 'auto').html('<span class="fa fa-spinner fa-pulse"></span>');

    var formData = $j('#profile-menu-request-form').serialize();

    var jqxhr = $j.post('/users/profile/create', formData, function(data) {

        if (data.code == 200) {

            $j('#profile-menu-request-submit').switchClass('btn-default', 'btn-success').html('<span class="fa fa-check"></span>');

            if (!$j('#profile-menu-newsletter').prop('checked')) {

                $j('#profile-menu-request-result').html('Results sent!');

            } else {

                $j('#profile-menu-request-result').html('Results sent! Please do not forget to confirm your subscription by clicking the link in the e-mail.');

            }

            $j('#profile-menu .primary-wrapper .request-caption').slideUp('fast');
            $j('#profile-menu .primary-wrapper .request-wrapper .email-info-wrapper').slideUp('fast');
            $j('#profile-menu .primary-wrapper .request-wrapper').css('padding-top', 0);

            $j('.sidebar .sidebar-signup').slideUp('fast');
            $j('.sidebar-results-logout').html('<a href="/auth/logout">Log out</a>');

            $j('#profile-menu .primary-wrapper .request-wrapper .subscribe-wrapper').hide();
            $j('#profile-menu .primary-wrapper .request-wrapper .confirmation-wrapper').fadeIn();

            $j('#profile-menu .primary-wrapper .request-wrapper').after('<div>Here is a link to your profile – share it with friends!</div><input readonly class="profile-link" value="https://www.16personalities.com/profiles/' + data.profileURL + '">');

            //$j('#profile-menu-toggle').before('<div class="fa fa-bell" id="alerts-menu-toggle"></div>');
            //$j('#profile-menu').before('<div id="alerts-menu"><div class="row heading">Notifications</div><div class="row no-alerts"><div class="col-md-12">No notifications found.</div></div></div>');

            $j('#profile-menu-logout').html('Log out');
            $j('#profile-menu-logout').parent().removeClass('col-xs-offset-6');
            $j('#profile-menu-logout').parent().before('<div class="col-xs-6 info-button-wrapper"><button class="btn btn-action-2" id="profile-menu-members-area"><span>Members Area</span></button></div>');

            $j('.sidebar .sidebar-signup').hide();
            $j('.navbar .navigation .login-links').hide();
            $j('#profile-menu .logout-button-wrapper').hide();
            $j('.sidebar .sidebar-results-widget .cta-note').hide();
            $j('.sidebar-results-logout').html('<a href="/auth/logout">Log out</a>');

            // For the results screen

            if ($j('.overlay').is(":visible")) {

                $j('.type-header-results').slideUp(500, 'easeInOutQuart');
                $j('.overlay').fadeOut();
                $j('.sidebar').show('slide', {direction: 'right'});

                if ($j(window).width() < 992) {
                    $j('.sticky-bottom-nav').show();
                }

            }

            // For the members area

            var pageFull = window.location.pathname;
            var page = pageFull.substr(pageFull.lastIndexOf('/') + 1);

            if (page == 'members-area') {

                window.location.reload(true);

            }

            resultsSent = true;
            inProgress = false;

        } else {

            $j('#profile-menu-request-error').html(data.message);
            $j('#profile-menu .primary-wrapper .request-wrapper .alert-wrapper').show();
            $j('#profile-menu-request-submit').removeClass('btn-default').addClass('btn-action-2');
            $j('#profile-menu-request-submit').css('cursor', 'pointer');
            $j('#profile-menu-request-submit').html('SEND');
            inProgress = false;

        }

    })
        .fail(function() {

            $j('#profile-menu-request-error').html('Could not connect to server - please try again.');
            $j('#profile-menu .primary-wrapper .request-wrapper .alert-wrapper').show();
            $j('#profile-menu-request-submit').removeClass('btn-default').addClass('btn-action-2');
            $j('#profile-menu-request-submit').css('cursor', 'pointer');
            $j('#profile-menu-request-submit').html('SEND');
            inProgress = false;

        })

});

$j('#profile-menu-request-form').submit(function(e) {

    $j('#profile-menu-request-submit').trigger('click');
    e.preventDefault();

});

$j(document).on('click', '#profile-menu .profile-link, #mobile-navigation .profile-link', function() { $j(this).select(); } );

$j(document).on('click', '#profile-menu-members-area', function () {

    window.location.href = '/members-area';

});


$j(document).on('click', '#profile-menu-logout', function () {

    $j('#profile-menu-logout span').html('Just a sec...').prepend('<span class="fa fa-spinner fa-pulse"></span>&nbsp;');

    var jqxhr = $j.post('/auth/logout-quiet', '_token=' + $j('#_token').val(), function() {
        window.location.reload(true);
    })

});

/* Login dialog */

$j(document).on('click', '#login-dialog .modal-footer .forgot-password', function () {

    $j('#login-dialog .login-section').hide('slide', {duration: 200, direction: 'left'}, function () {

        $j('#loginDialogLabel').html('Forgot your password?');
        $j('#login-dialog .modal-body.reminder-section .reminder-alert').hide();
        $j('#login-dialog .modal-footer .forgot-password').html('<span class="fa fa-caret-left"></span>&nbsp;Back to log in screen');
        $j('#login-dialog .modal-footer .forgot-password').switchClass('forgot-password', 'show-login');
        $j('#login-dialog .modal-footer .login-button').html('Send link');
        $j('#login-dialog .modal-footer .login-button').switchClass('login-button', 'reset-button');
        $j('#login-dialog .reminder-section').show('slide', {duration: 200, direction: 'right'});

    });

});

$j(document).on('click', '#login-dialog .modal-footer .show-login', function () {

    $j('#login-dialog .reminder-section').hide('slide', {duration: 200, direction: 'right'}, function () {

        $j('#loginDialogLabel').html('Members login');
        $j('#login-dialog .modal-body.login-section .login-alert').hide();
        $j('#login-dialog .modal-footer .show-login').html('Forgot password?');
        $j('#login-dialog .modal-footer .show-login').switchClass('show-login', 'forgot-password');
        $j('#login-dialog .modal-footer .reset-button').html('Log in');
        $j('#login-dialog .modal-footer .reset-button').switchClass('reset-button', 'login-button');
        $j('#login-dialog .login-section').show('slide', {duration: 200, direction: 'left'});

    });

});

$j(document).on('click', '#login-dialog .modal-footer .login-button', function () {

    if (inProgress) return false;

    var validationFailed = false;

    $j('#login-dialog .login-section .email, #login-dialog .login-section .password').removeClass('invalid');

    var email = $j('#login-dialog .login-section .email').val();
    var password = $j('#login-dialog .login-section .password').val();

    if (email == '') {

        $j('#login-dialog .login-section .email').addClass('invalid');
        validationFailed = true;

    }

    if (password == '') {

        $j('#login-dialog .login-section .password').addClass('invalid');
        validationFailed = true;

    }

    if (validationFailed) return false;

    inProgress = true;

    $j('#login-dialog .modal-footer .login-button').switchClass('btn-action-2', 'btn-default').css('cursor', 'default').html('<span class="fa fa-spinner fa-pulse"></span>&nbsp;<span>Please wait...</span>');

    var parameters = $j('#login-dialog .login-section form').serialize();

    var jqxhr = $j.post('/auth/login-quiet', parameters, function(data) {

        if (data.code == 401) {

            $j('#login-dialog .modal-body.login-section .login-alert').removeClass('alert-success').addClass('alert-danger').html(data.message).show();
            $j('#login-dialog').effect('shake', {distance: 10});
            $j('#login-dialog .modal-footer .login-button').switchClass('btn-default', 'btn-action-2').css('cursor', 'pointer').html('Log in');
            inProgress = false;

        } else if (data.code == 200) {

            $j('#login-dialog .modal-body.login-section .login-alert').removeClass('alert-danger').addClass('alert-success').html('You are now logged in. Please wait...').show();
            window.location.reload();
            inProgress = false;

        }

    })
    .fail(function() {

        $j('#login-dialog .modal-body.login-section .login-alert').removeClass('alert-success').addClass('alert-danger').html('Could not connect to server - please try again.').show();
        $j('#login-dialog .modal-footer .login-button').switchClass('btn-default', 'btn-action-2').css('cursor', 'pointer').html('Log in');
        inProgress = false;

    })

});

$j(document).on('click', '#login-dialog .modal-footer .reset-button', function () {

    if (inProgress) return false;

    var validationFailed = false;

    $j('#login-dialog .reminder-section .email').removeClass('invalid');

    var email = $j('#login-dialog .reminder-section .email').val();

    if (email == '') {

        $j('#login-dialog .reminder-section .email').addClass('invalid');
        return false;

    }

    inProgress = true;

    $j('#login-dialog .modal-footer .reset-button').switchClass('btn-action-2', 'btn-default').css('cursor', 'default').html('<span class="fa fa-spinner fa-pulse"></span>&nbsp;<span>Please wait...</span>');

    var parameters = $j('#login-dialog .reminder-section form').serialize();

    var jqxhr = $j.post('/auth/reset-password-quiet', parameters, function(data) {

        inProgress = false;
        $j('#login-dialog .modal-footer .reset-button').switchClass('btn-default', 'btn-action-2').css('cursor', 'pointer').html('Send link');

        if (data.code == 200) {

            $j('#login-dialog .modal-body.reminder-section .reminder-alert').removeClass('alert-danger').addClass('alert-success').html(data.message).show();

        } else  {

            $j('#login-dialog .modal-body.reminder-section .reminder-alert').removeClass('alert-success').addClass('alert-danger').html(data.message).show();
            $j('#login-dialog').effect('shake', {distance: 10});

        }

    })
    .fail(function() {

            alert(jqxhr.responseText);

        $j('#login-dialog .modal-body.reminder-section .reminder-alert').removeClass('alert-success').addClass('alert-danger').html('Could not connect to server - please try again.').show();
        $j('#login-dialog .modal-footer .reset-button').switchClass('btn-default', 'btn-action-2').css('cursor', 'pointer').html('Send link');
        inProgress = false;

    })

});

$j('#login-dialog .login-section input').keypress(function(e) {

    if (e.which == 13) {

        e.preventDefault();
        $j('#login-dialog .modal-footer .login-button').trigger('click');

    }

});

$j('#login-dialog .reminder-section input').keypress(function(e) {

    if (e.which == 13) {

        e.preventDefault();
        $j('#login-dialog .modal-footer .reset-button').trigger('click');

    }

});

$j('#mobile-navigation .profile-link-wrapper .action-register').click(function() {

    $j(this).hide();
    $j('#mobile-navigation .profile-link-wrapper .signup-wrapper').fadeIn();

});

$j(document).on('submit', '#mobile-navigation .profile-link-wrapper .signup-wrapper form', function (e) {

    e.preventDefault();
    $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup').click();

});

$j(document).on('click', '#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup', function () {

    if (inProgress) return;

    $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .alert').hide();
    $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .email').removeClass('invalid');

    var email = $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .email').val();
    var etapos = email.indexOf('@');
    var dotpos = email.lastIndexOf('.');

    if (email == '' || etapos < 1 || dotpos < etapos + 2 || dotpos + 2 >= email.length) {
        $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .email').addClass('invalid');
        return false;
    }

    inProgress = true;

    $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup').removeClass('btn-action').addClass('btn-default').css('cursor', 'auto').html('<span class="fa fa-spinner fa-pulse"></span>');

    var formData = $j('#mobile-navigation .profile-link-wrapper .signup-wrapper form').serialize();

    var jqxhr = $j.post('/users/profile/create', formData, function(data) {

            inProgress = false;

            if (data.code == 200) {

                $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup').switchClass('btn-default', 'btn-success').html('<span class="fa fa-check"></span>');
                $j('#mobile-navigation .profile-link-wrapper .signup-wrapper').html('<div class="alert alert-success">Results sent! Just a moment...</div>');

                window.location.reload();

            } else {

                $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .alert').html(data.message).fadeIn();
                $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('SEND');

            }

        })
        .fail(function() {

            $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .alert').html(data.message).fadeIn();
            $j('#mobile-navigation .profile-link-wrapper .signup-wrapper .action-signup').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('SEND');
            inProgress = false;

        })

});