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
      $('#block-system-user-menu .block-title, #block-myassist-user-avatar').click(function(e) {
        e.preventDefault();
        $('#block-system-user-menu').toggleClass('open');
      });
      
      // Toggle search
      $('#block-search-form .block-title').click(function() {
        $('#block-search-form').toggleClass('open');
      });
      
      
      /*
       * Message Form script
       */
      
      //var messageForm = $("#answers-answer-node-form");
      //var messageField = messageForm.find("textarea[id^=edit-body]");

      var messageForm = $(".node-answers-question form[id^=comment-form]");
      var messageField = messageForm.find("textarea[id^=edit-comment-body]");

      var originalValues = {};
      messageForm.find("input,select").each(function(){
        if (this.name) {
          originalValues[this.name] = this.value;
        }
      });

      $("#answers-btn-lock, .flag-action").click(function(event){
        var msg = window.prompt(Drupal.t("Skriv en afsluttende besked, så vi ved, hvorfor du lukker spørgsmålet:\n(Let feltet være tomt for at lukke tråden uden en afsluttende besked)"));
        if (msg === null) { // The user clicked cancel
          event.stopPropagation(); // Abort event so nothing happens
          event.preventDefault();
          return false;
        } else {
          if (msg) { // The user actually entered some text
            event.stopPropagation();
            event.preventDefault();
            var data = $.extend({}, originalValues);
            data[messageField.attr("name")] = msg;

            $.ajax({
              url: messageForm.attr("action") || document.location,
              type: messageForm.attr("method") || "post",
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

