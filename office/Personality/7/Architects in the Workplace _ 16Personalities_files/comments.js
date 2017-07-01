var $j = jQuery.noConflict();
var inProgress = false;
var commentType = 1;
var responseTo = 0;

$j(document).ready(function() {

	var hash = window.location.hash;

	if (hash == '#comments') {

		$j('#comment-tabs a[href="#other"]').tab('show');
		$j('html,body').animate({scrollTop: $j('#comment-tabs a[href="#other"]').offset().top - 10}, 'fast');

	}

});

$j(document).on('click', '.reply-link', function (e) {

    e.preventDefault();
    var thisTransfer = $j(this);
    commentType = 1;
    responseTo = $j(thisTransfer).data('id');

    if ($j(this).children('.comment-reply-text').html() != 'Cancel') {

		$j(thisTransfer).addClass('active').children('.comment-reply-text').html('Cancel');
		$j(thisTransfer).parent().append('<div class="comment-reply-wrapper">' + $j('.js-template.comment-reply').html() + '</div>');
        $j(thisTransfer).parent().find('.comment-reply-wrapper .comment-publish').data('parent', responseTo);


	} else {

        $j(thisTransfer).removeClass('active').children('.comment-reply-text').html('Reply');
		$j(thisTransfer).parent().find('.comment-reply-wrapper').remove();
	}

});

$j(document).on('click', '.comment-publish', function () {

	if (inProgress) return false;
    var validationFailed = false;

    var direct = $j(this).data('direct');
    var parent = $j(this).data('parent');
    var thisTransfer = $j(this);
    var mainForm = $j(thisTransfer).closest('form');

	$j(mainForm).find('.comment-text, .comment-username').removeClass('invalid');

	var commentText = $j(mainForm).find('.comment-text').val();
	var commentUsername = $j(mainForm).find('.comment-username').val();

    if (commentText == '') {
        $j(mainForm).find('.comment-text').addClass('invalid');
		validationFailed = true;
	}

	if (commentUsername == '') {
        $j(mainForm).find('.comment-username').addClass('invalid');
		validationFailed = true;
	}

    if (validationFailed) return false;
	inProgress = true;
	
	$j(mainForm).find('.comment-publish').removeClass('btn-action-2').addClass('btn-default').css('cursor', 'default').html('<span class="fa fa-spinner fa-pulse"></span>');
	
	var parameters = '_token=' + $j('#_token').val() + '&comment=' + encodeURIComponent(commentText) + '&name=' + encodeURIComponent(commentUsername) + '&direct=' + direct + '&parent=' + parent + '&page-type=' + $j('#page-type').val() + '&page-id=' + $j('#page-id').val();

	var jqxhr = $j.post('/comments/publish', parameters, function(data) {
		inProgress = false;
		if (data.code == 200) {
            $j(mainForm).find('.alert').removeClass('alert-danger').addClass('alert-success').html('Thank you for the comment! It will be published shortly.').css('display', 'inline-block');
            $j(mainForm).find('.comment-publish').css('cursor', 'pointer').removeClass('btn-default').addClass('btn-action-2').html('<span>Publish</span>');
		} else {
            $j(mainForm).find('.alert').removeClass('alert-success').addClass('alert-danger').html(data.message).css('display', 'inline-block');
            $j(mainForm).find('.comment-publish').css('cursor', 'pointer').removeClass('btn-default').addClass('btn-action-2').html('<span>Publish</span>');
		}
	})
	.fail(function() {
		inProgress = false;
        $j(mainForm).find('.alert').removeClass('alert-success').addClass('alert-danger').html('Could not connect to server - please try again.').css('display', 'inline-block');
        $j(mainForm).find('.comment-publish').css('cursor', 'pointer').removeClass('btn-default').addClass('btn-action-2').html('<span>Publish</span>');
	})

});

$j(document).on('submit', 'form', function (e) {

	$j(this).find('.comment-publish').trigger('click');
	e.preventDefault();

});

$j(document).on('click', '.upvote-comment', function (e) {

	e.preventDefault();

	var thisTransfer = this;
	var commentRep = $j(this).parent().data('rep');

	if (inProgress) return false;

	inProgress = true;

    var parameters = '_token=' + $j('#_token').val() + '&comment=' + $j(this).data('id') + '&direction=upvote';
    
    var jqxhr = $j.post('/comments/reputation', parameters, function(data) {

		inProgress = false;
		if (data.code == 200) {

			commentRep++;
			$j(thisTransfer).parent().data('rep', commentRep);
			if (commentRep == 1) {
				$j(thisTransfer).next('span').addClass('comment-good-rep');
				$j(thisTransfer).next('span').html('+' + commentRep);
			} else if (commentRep == 0) {
				$j(thisTransfer).next('span').removeClass('comment-bad-rep');
				$j(thisTransfer).next('span').html(commentRep);
			} else if (commentRep > 0) {
				$j(thisTransfer).next('span').html('+' + commentRep);
			} else {
				$j(thisTransfer).next('span').html(commentRep);
			}

		} else {
			alert(data.message);
		}
		
	})
	.fail(function() {
		inProgress = false;
		alert('Could not connect to server - please try again later.');
	})

});

$j(document).on('click', '.downvote-comment', function (e) {

	e.preventDefault();

	var thisTransfer = this;
	var commentRep = $j(this).parent().data('rep');

	if (inProgress) return false;

	inProgress = true;

    var parameters = '_token=' + $j('#_token').val() + '&comment=' + $j(this).data('id') + '&direction=downvote';
    
    var jqxhr = $j.post('/comments/reputation', parameters, function(data) {
    	
		inProgress = false;
		if (data.code == 200) {

			commentRep--;
			$j(thisTransfer).parent().data('rep', commentRep);
			if (commentRep == -1) {
				$j(thisTransfer).prev('span').addClass('comment-bad-rep');
				$j(thisTransfer).prev('span').html(commentRep);
			} else if (commentRep == 0) {
				$j(thisTransfer).prev('span').removeClass('comment-good-rep');
				$j(thisTransfer).prev('span').html(commentRep);
			} else if (commentRep > 0) {
				$j(thisTransfer).prev('span').html('+' + commentRep);
			} else {
				$j(thisTransfer).prev('span').html(commentRep);
			}

		} else {
			alert(data.message);
		}

	})
	.fail(function() {
		inProgress = false;
		alert('Could not connect to server - please try again later.');
	})

});