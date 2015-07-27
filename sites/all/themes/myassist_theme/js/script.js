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
      var originalValues = {};
      $("#answers-answer-node-form").find("input,select").each(function(){
        if (this.name) {
          originalValues[this.name] = this.value;
        }
      });




      $("#answers-btn-lock").click(function(event){
        var msg = window.prompt(Drupal.t("Skriv en afsluttende besked, så vi ved, hvorfor du lukker spørgsmålet:\n(Let feltet være tomt for at lukke tråden uden en afsluttende besked)"));
        if (msg === null) { // The user clicked cancel
          event.stopPropagation(); // Abort event so nothing happens
          event.preventDefault();
          return false;
        } else {
          if (msg) { // The user actually entered some text
            event.stopPropagation();
            event.preventDefault();
            var form = $("#answers-answer-node-form");
            var data = $.extend({}, originalValues);

            var commentField = form.find("textarea[id^=edit-body]");
            data[commentField.attr("name")] = msg;

            $.ajax({
              url: form.attr("action") || document.location,
              type: form.attr("method") || "post",
              data: data,
              success: function(){
                document.location.href = this.href;
              }.bind(this)
            });
            return false;

          } else { // The user left the field empty
            return true; // Let the lock button do its regular thing (go to /node/<nodeid>/lock)
          }
        }
      });
    }
  };

})(jQuery, Drupal, this, this.document);