/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

// To understand behaviors, see https://drupal.org/node/756722#behaviors


  Drupal.behaviors.headerResponsive = {
    attach: function(context, settings) {
      
      // Toggle user action menu
      $('#block-system-user-menu .block-title').click(function() {
        $('#block-system-user-menu').toggleClass('open');
      });
      
      // Toggle search
      $('#block-search-form .block-title').click(function() {
        $('#block-search-form').toggleClass('open');
      });

    }
  };

  var updateOffset = function() {
    var offset = $("#toolbar").height();
    if (offset && !isNaN(offset)) {
      $("#page > *").each(function(){
        var el = $(this);
        if (el.css("position") === "fixed") {
          el.offset({top:offset});
        }
      });

    }
  };

  Drupal.behaviors.toolbarOffset = {
    attach: function(context, settings) {
      $('#toolbar a.toggle', context).click(updateOffset);
    }
  };

  $(updateOffset);
  $(window).resize(updateOffset);
  
})(jQuery, Drupal, this, this.document);


(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.headerResponsive = {
    attach: function(context, settings) {
      $("#answers-btn-lock").click(function(event){
        if (window.confirm(Drupal.t("Du er nu ved at lukke dit spørgsmål, du vil dermed ikke modtage flere assists til spørgsmålet, men spørgsmålet og dine assists vil stadig være synlige på sitet, og du kan altid oprette et nyt spørgsmål herinde."))) {
          return true;
        } else {
          event.stopPropagation();
          event.preventDefault();
          return false;
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);