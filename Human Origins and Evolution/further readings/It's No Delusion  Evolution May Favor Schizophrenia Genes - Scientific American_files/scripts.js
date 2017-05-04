// Mura.DisplayObject.{display-object-directory-name}
Mura.DisplayObject.js_pullquote = Mura.UI.extend({

  // Mura invokes the 'render()' method by default
  render: function() {

    // objectparams (configurator settings) are available under 'this.context.{yourVar}'
    var source =
          this.context.source === undefined
            ? 'Enter some text.'
            : this.context.source,
        contenturl = document.head.querySelector("[property='og:url']").content,
        contenttitle = document.head.querySelector("[property='og:title']").content,
        shareLinks = '<ul class="blockquote-share__lt-module"><li><a href="https://www.facebook.com/sharer/sharer.php?p[url]=' + contenturl + '?wt.mc=SA_Facebook-Share"><span class="share-tooltip" aria-label="Share on Facebook" tabindex="0"><span class="icon icon--subtle icon__facebook--black"></span></span></a></li><li><a href="https://twitter.com/intent/tweet?url=' + contenturl + '?wt.mc=SA_Twitter-Share&amp;text=' + contenttitle + '&amp;hashtags=science"><span class="share-tooltip" aria-label="Share on Twitter" tabindex="0"><span class="icon icon--subtle icon__twitter--black"></span></span></a></li></ul>';

    Mura(this.context.targetEl).html('<div class="article-grid__main__break-share"><div class="article-quote"><blockquote class="blockquote__lt-module t_quote">' + source + '</blockquote>' + shareLinks + '</div></div>');
  }

});
