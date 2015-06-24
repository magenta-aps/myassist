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

      
      $(".search-toggle").click(function(event){
        $("#block-search-form").addClass("forceShow");
        event.stopPropagation();
        return false;
      });

      $(document).click(function(event) {
        if(!$(event.target).closest("#block-search-form").length) {
          $("#block-search-form").removeClass("forceShow");
        }
      });


      var bodyPadding = null;
      var relocateButtons = function(){
        var newBodyPadding = $("body").css("paddingTop");
        if (newBodyPadding !== bodyPadding) {
          $(".mm-toggle").css({top:newBodyPadding});
          $(".search-toggle").css({top:newBodyPadding});
          bodyPadding = newBodyPadding;
        }
      };
      $(window).resize(relocateButtons);
      $(relocateButtons);

    }
  };

  var updateOffset = function() {
    var offset = $("#toolbar").height();
    if (offset && !isNaN(offset)) {
      $("#header").offset({top:offset});
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
