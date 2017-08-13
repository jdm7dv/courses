'use strict';

var Search = require('plos-search');

var search = new Search('firefly');

search.on('success', function (data) {
    data.forEach(function (article) {
        console.log('Id: ', article.id);
        console.log('Publication date: ', article.publication_date);
        console.log('Article type: ', article.article_type);
        console.log('Author: ', article.author_display); // Array of authors 
        console.log('Abstract: ', article.abstract);
        console.log('Title: ', article.title_display);
    });
});

search.fetch();