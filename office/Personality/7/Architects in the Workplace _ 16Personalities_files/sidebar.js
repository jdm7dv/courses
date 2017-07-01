var $j = jQuery.noConflict();

var inProgress = false;
var Stage2 = false;

$j(document).on('click', '#results-send-button', function () {
	
	if (inProgress) return;

	if (!Stage2) {
		$j('.results-send-email-error-row').hide();
		$j('#email').css('border', '1px solid #E1E1E1');

		var email = $j('#email').val();
		var etapos = email.indexOf('@');
		var dotpos = email.lastIndexOf('.');

		if (email == '' || etapos < 1 || dotpos < etapos + 2 || dotpos + 2 >= email.length) {
			$j('#email').css('border', '2px solid #CD3B32');
			return false;
		}
		
		inProgress = true;
		
		$j('#results-send-button').removeClass('btn-action').addClass('btn-default');
		$j('#results-send-button').css('cursor', 'auto');
		$j('#results-send-button').html('<span>Please wait...</span>');
		
		var formData = $j('input').serialize();
		
		var jqxhr = $j.post('/users/profile/create', formData, function(data) {
		
			var response = JSON.parse(data);
		
			if (response[0] == 'OK') {

				Stage2 = true;
		
				$j('#results-send-button').hide();
				$j('#results-close-button').html('Close');

				if ($j('#newsletter').prop('checked')) {
					$j('#confirmation-message').html('<p>Please do not forget to confirm your subscription by clicking the link in the e-mail.</p>');
				}

				$j('#send-dialog-step1').hide();
				var personalLink = response[2];
				$j('#friend-link').val('https://www.16personalities.com/free-personality-test/' + personalLink);
				$j('#twitter-custom-link').attr('href', 'https://twitter.com/share?url=https://www.16personalities.com/free-personality-test/' + personalLink + "&text=I%20am%20'The%20" + $j('#nice-type-field').val() + "'%20(" + $j('#nice-type-code').val() + ').%20What%20is%20your%20type?&via=16Personalities&hashtags=16Personalities');
				$j('#facebook-custom-link').attr('href', 'https://www.facebook.com/sharer/sharer.php?u=https://www.16personalities.com/free-personality-test/' + personalLink);
				$j('#google-custom-link').attr('href', 'https://plus.google.com/share?url=https://www.16personalities.com/free-personality-test/' + personalLink);
				$j('#pinterest-custom-link').attr('href', '//pinterest.com/pin/create/link/?url=https%3A%2F%2Fwww.16personalities.com%2Ffree-personality-test%2F' + personalLink + '&media=https%3A%2F%2Fwww.16personalities.com%2Fimages%2Flogo_main.png&description=Pin%20It!');
				$j('#send-dialog-step2').show();
				
			} else {
		
				$j('.results-send-email-error').html(response[1]);
				$j('.results-send-email-error-row').show();
				$j('#results-send-button').removeClass('btn-default').addClass('btn-action');
				$j('#results-send-button').css('cursor', 'pointer');
				$j('#results-send-button').html("<span>Send results</span>");
				inProgress = false;
		
			}
		
		})
		.fail(function() {

			$j('.results-send-email-error').html('Could not connect to server - please try again.');
			$j('.results-send-email-error-row').show();
			$j('#results-send-button').removeClass('btn-default').addClass('btn-action');
			$j('#results-send-button').css('cursor', 'pointer');
			$j('#results-send-button').html("<span>Send results</span>");
			inProgress = false;

		})

	}

});

$j('#email').keypress(function(e) {

	if (e.which == 13) {

		e.preventDefault();
		$j('#results-send-button').trigger('click');

	}

});

$j('#friend-link').click(function() { $j(this).select(); } );

$j('#send-dialog').on('hidden.bs.modal', function () {
	location.reload(true);
});

$j('[data-toggle="tooltip"]').tooltip();

function checkSticky () {

    var topWidgetHeight = $j('.sidebar-results-widget').height();
    var stickyThreshold = $j('.header-scene').height() + topWidgetHeight + 245;
    var stoppingPoint = $j('.type-description-wrapper').height();

    if ($j(document).scrollTop() > stickyThreshold && $j(window).height() > 0 && $j(window).width() > 1010) {

		var newMargin = $j(document).scrollTop() - stickyThreshold;

		if (newMargin > $j(document).height() - stickyThreshold - $j('#stickySidebar').height() - 450) {
			newMargin = $j(document).height() - stickyThreshold - $j('#stickySidebar').height() - 450;
		}

        if (newMargin + topWidgetHeight + 470 < stoppingPoint) {
            $j('#stickySidebar').css('margin-top', newMargin + 'px');
        }

	} else {
        $j('#stickySidebar').css('margin-top', '17px');
    }

    if ($j(window).width() < 800) {
        var additionalOffset = 450;
    } else {
        var additionalOffset = 350;
    }

    if ($j(document).scrollTop() + $j('.header-scene').height() + additionalOffset > $j('.type-comments').offset().top) {

        $j('.type-comments').removeClass('grey');
        $j('.social-wrapper .social-item').addClass('higher-opacity');

    } else {

        $j('.type-comments').addClass('grey');
        $j('.social-wrapper .social-item').removeClass('higher-opacity');

    }

    if ($j(document).scrollTop() + $j(window).height() + 200 > $j('.post-type .social-wrapper').offset().top) {
        $j('.navigation-buttons .fixed-nav').fadeOut();
    } else if ($j(window).width() < 992 && !$j('.type-header-results').is(':visible')) {
        $j('.navigation-buttons .fixed-nav').fadeIn();
    }

}

$j(window).on('scroll', function () {
	checkSticky();
});

$j(document).on('click', '.sidebar .sidebar-signup', function () {

    $j(this).hide();
    $j('.sidebar .cta-note').hide();
    $j('.sidebar .signup-wrapper').fadeIn();
    $j('.sidebar .sidebar-results-logout').hide();

});

$j(document).on('click', '.sidebar .action-signup', function () {

    if (inProgress || resultsSent) return;

    $j('.sidebar .alert').hide();
    $j('.sidebar .email').removeClass('invalid');

    var email = $j('.sidebar .email').val();
    var etapos = email.indexOf('@');
    var dotpos = email.lastIndexOf('.');

    if (email == '' || etapos < 1 || dotpos < etapos + 2 || dotpos + 2 >= email.length) {
        $j('.sidebar .email').addClass('invalid');
        return false;
    }

    inProgress = true;

    $j('.sidebar .action-signup').removeClass('btn-action').addClass('btn-default').css('cursor', 'auto').html('<span class="fa fa-spinner fa-pulse"></span>');

    var formData = $j('.sidebar #signup-form').serialize();

    var jqxhr = $j.post('/users/profile/create', formData, function(data) {

        if (data.code == 200) {

            $j('.sidebar .action-signup').switchClass('btn-default', 'btn-success').html('<span class="fa fa-check"></span>');

            if (!$j('.sidebar newsletter').prop('checked')) {
                $j('.sidebar .signup-wrapper').html('<div class="alert alert-success">Results sent!</div>');
            } else {
                $j('.sidebar .signup-wrapper').html('<div class="alert alert-success">Results sent! Please do not forget to confirm your subscription by clicking the link in the e-mail.</div>');
            }

            $j('.sidebar .alert').show();

            $j('.navigation .login-links').hide();

            $j('#profile-menu .primary-wrapper .request-caption').slideUp('fast');
            $j('#profile-menu .primary-wrapper .request-wrapper .email-info-wrapper').slideUp('fast');
            $j('#profile-menu .primary-wrapper .request-wrapper').css('padding-top', 0);

            $j('.btn-sidebar-signup').slideUp('fast');

            $j('#profile-menu .primary-wrapper .request-wrapper .subscribe-wrapper').hide();

            $j('#profile-menu .primary-wrapper .request-wrapper').after('<div>Here is a link to your profile – share it with friends!</div><input readonly class="profile-link" value="https://www.16personalities.com/profiles/' + data.profileURL + '">');

            $j('.sidebar .post-signup-wrapper').show();
            $j('.sidebar .post-signup-wrapper .profile-link').val('https://www.16personalities.com/profiles/' + data.profileURL);

            $j('#profile-menu-logout').html('<span>Log out</span>');
            $j('#profile-menu-logout').parent().removeClass('col-xs-offset-6');
            $j('#profile-menu-logout').parent().before('<div class="col-xs-6 info-button-wrapper"><button class="btn btn-action-2" id="profile-menu-members-area"><span>Members Area</span></button></div>');

            $j('.sidebar-results-logout').html('<a href="/auth/logout">Log out</a>');

            resultsSent = true;
            inProgress = false;

        } else {

            $j('.sidebar .alert').html(data.message).show();
            $j('.sidebar .action-signup').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('<span>SEND</span>');
            inProgress = false;

        }

    })
    .fail(function() {

        $j('.sidebar .alert').html('Could not connect to server - please try again.').show();
        $j('.sidebar .action-signup').removeClass('btn-default').addClass('btn-action').css('cursor', 'pointer').html('<span>SEND</span>');
        inProgress = false;

    })

});

$j('.sidebar .email').keypress(function(e) {

    if (e.which == 13) {

        e.preventDefault();
        $j('.sidebar .action-signup').trigger('click');

    }

});

$j('.sidebar .profile-link').click(function() { $j(this).select(); } );

$j('#bottom-nav-list').change(function() {
	window.location.href = $j('option:selected', this).data('page');
});

$j(document).on('click', '#bottom-nav-button', function () {
	window.location.href = $j('option:selected', '#bottom-nav-list').data('page');
});

$j('#facebook-share-link').click(function(e) {

    var pageFull = window.location.pathname;
    var page = pageFull.substr(pageFull.lastIndexOf('/') + 1);

    if (page != 'test-results' && $j('.type-header-results').css('display') != 'block') {

        e.preventDefault();

        FB.ui({
                method: 'share',
                href: window.location.href.toLowerCase(),
            },
            function (response) {
            }
        );

    }

});

$j('#compare-dialog input').click(function() { $j(this).select(); } );