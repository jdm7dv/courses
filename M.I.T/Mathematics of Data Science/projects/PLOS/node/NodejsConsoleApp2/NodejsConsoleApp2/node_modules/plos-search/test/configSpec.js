var expect = require('chai').expect
,	config = require('../lib/config')()
,	search = require('../lib/plosSearch')

,	apiKey = require('../lib/config/apiKey')
;

describe('Config', function() {
	describe('setup', function() {
		it('should load development config', function() {
			expect(config.mode).to.equal('development');
		});

		it('should load api key from config', function() {
			expect(config.api_key).to.equal(apiKey);
		});
	});
});