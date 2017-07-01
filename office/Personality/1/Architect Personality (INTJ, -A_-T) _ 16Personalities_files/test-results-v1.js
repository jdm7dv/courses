var $j = jQuery.noConflict();
var inProgress = false;
var Stage2 = false;
var resultsUpdated = false;
var resultsSent = false;

$j('.sticky-bottom-nav').hide();
$j('.navigation-buttons .fixed-nav').hide();

$j('html, body').animate({ scrollTop: $j('.type-header-results').offset().top });

$j(document).on('click', '.update-profile', function () {
	
	if (inProgress || resultsUpdated) return;

	inProgress = true;

    $j('.update-profile').css('cursor', 'auto').removeClass('btn-action-2').addClass('btn-default').html('Please wait...');
	
	var formData = $j('.type-info-fields input').serialize();

	var jqxhr = $j.post('/users/update-type', formData, function(data) {
		inProgress = false;
		if (data.code == 200) {
            $j('.update-profile').removeClass('btn-default').addClass('btn-green').html('<span class="fa fa-check"></span>&nbsp;Updated!');
			resultsUpdated = true;
		} else {
			alert(data.message);
            $j('.update-profile').css('cursor', 'pointer').removeClass('btn-default').addClass('btn-action-2').html('Update your profile');
		}
	})
	.fail(function() {
		alert('Could not connect to server - please try again.');
        $j('.update-profile').css('cursor', 'pointer').removeClass('btn-default').addClass('btn-action-2').html('Update your profile');
		inProgress = false;
	})

});

$j('#friend-link').click(function() { $j(this).select(); } );
$j('#friend-link-2').click(function() { $j(this).select(); } );

$j('#start-reading-fixed .get-results').click(function () {

    $j('html, body').animate({scrollTop: $j('#request-wrapper').offset().top - 300});
    if (!$j('#request-wrapper .request-info-wrapper').is(':visible')) {
        $j('#request-trigger').trigger('click');
    }

});

$j('#results-start-button, #start-reading-fixed .start-reading, .type-description .overlay').click(function () {

    $j('.homepage-navigation-wrapper').removeClass('results-nav');
    $j('.type-header-results').slideUp(500, 'easeInOutQuart');
    $j('.overlay').fadeOut();
    $j('.sidebar').show('slide', {direction: 'right'});

    $j('.sticky-bottom-nav').show('slide', {direction: 'down'});

    $j('html, body').animate({ scrollTop: 0 }, 500);

});

var timeout = null;

$j(window).scroll(function () {

    if ($j(window).width() < 768) {
        if (!timeout) {
            timeout = setTimeout(function () {

                clearTimeout(timeout);
                timeout = null;
                var startButtonPosition = $j('.type-header-results .action-wrapper').offset().top;
                if ($j(document).scrollTop() + $j(window).height() >= startButtonPosition) {
                    $j('#results-start-button').show();
                    $j('#start-reading-fixed').slideUp(100);
                } else {
                    $j('#results-start-button').hide();
                    $j('#start-reading-fixed').slideDown(100);
                }

            }, 250);
        }
    } else {
        $j('#results-start-button').show();
        $j('#start-reading-fixed').hide();
    }

});


$j('#facebook-share-link-top').click(function(e) {

	e.preventDefault();

	FB.ui({
		method: 'share',
		href: 'https://www.16personalities.com/free-personality-test',
		},
		function(response){}
	);

});

$j('#request-trigger').click(function() {

    $j('.invitee-wrapper').hide();
    $j('#request-trigger').animate({
        right: '0'
    }, 300, function() {
        $j('#request-trigger').html('<span>Send</span>');
        $j('#request-trigger').attr('id', 'request-send');
        $j('.request-info-wrapper').show();
        var emailBoxWidth = $j('#request-wrapper .request-info-wrapper').width() - 58;
        $j('#request-email').animate({
            right: '0',
            width: '100%'
        }, 300, function() {
            $j('#request-wrapper .subscribe-wrapper').show('slide', {direction: 'down'});
        });
    });

});

$j(document).on('click', '#request-send', function () {

    if (inProgress || resultsSent) return;

    $j('#request-wrapper .alert-wrapper').hide();
    $j('#request-email').removeClass('invalid');

    var email = $j('#request-email').val();
    var etapos = email.indexOf('@');
    var dotpos = email.lastIndexOf('.');

    if (email == '' || etapos < 1 || dotpos < etapos + 2 || dotpos + 2 >= email.length) {
        $j('#request-email').addClass('invalid');
        return false;
    }

    inProgress = true;
    $j('#request-send').removeClass('btn-action').addClass('btn-default').css('cursor', 'auto').html('<span class="fa fa-spinner fa-pulse"></span>');
    var parameters = $j('#request-form').serialize() + '&_token=' + $j('#_token').val();

    var jqxhr = $j.post('/users/profile/create', parameters, function(data) {

        if (data.code == 200) {

            $j('#request-send').switchClass('btn-default', 'btn-green').html('<span class="fa fa-check"></span>');

            if (!$j('#newsletter').prop('checked')) {
                $j('#result-message').html('Results sent!');
            } else {
                $j('#result-message').html('Results sent! Please do not forget to confirm your subscription by clicking the link in the e-mail.');
            }

            $j('#profile-menu .primary-wrapper').html('<div>Here is a link to your profile – share it with friends!</div><input readonly class="profile-link" value="https://www.16personalities.com/profiles/' + data.profileURL + '">');

            $j('#profile-menu-logout').html('<span>Log out</span>');
            $j('#profile-menu-logout').parent().removeClass('col-xs-offset-6');
            $j('#profile-menu-logout').parent().before('<div class="col-xs-6 info-button-wrapper"><button class="btn btn-action-2" id="profile-menu-members-area"><span>Members Area</span></button></div>');

            $j('.navbar .navigation .login-links').hide();
            $j('#profile-menu .logout-button-wrapper').hide();
            $j('.sidebar .sidebar-signup').hide();
            $j('.sidebar .sidebar-results-widget .cta-note').hide();
            $j('.sidebar-results-logout').html('<a href="/auth/logout">Log out</a>');

            $j('#request-wrapper .subscribe-wrapper').hide();
            $j('#request-wrapper .confirmation-wrapper').show();
            resultsSent = true;
            inProgress = false;

        } else {

            $j('#alert-message').html(data.message);
            $j('#request-wrapper .alert-wrapper').show();
            $j('#request-send').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('<span>SEND</span>');
            inProgress = false;

        }

    })
    .fail(function() {

        $j('#alert-message').html('Could not connect to server - please try again.');
        $j('#request-wrapper .alert-wrapper').show();
        $j('#request-send').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('<span>SEND</span>');
        inProgress = false;

    })

});

$j('#request-form').submit(function(e) {

    $j('#request-send').trigger('click');
    e.preventDefault();

});

$j('#request-form #request-email').keypress(function(e) {

    if (e.which == 13) {

        e.preventDefault();
        $j('#request-send').trigger('click');

    }

});