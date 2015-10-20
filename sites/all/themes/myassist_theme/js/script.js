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


  Drupal.behaviors.my_custom_behavior = {
    attach: function(context, settings) {
  
      // Toggle menu on small screens
      $('.mm-toggle').click(function() {
        $('#mm').toggleClass('open');
      });
  
    }
  };


  Drupal.behaviors.headerResponsive = {
    attach: function(context, settings) {

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

  Drupal.behaviors.toolbarOffset = {
    attach: function(context, settings) {
      $('#toolbar a.toggle', context).click(updateOffset);
    }
  };

  $(updateOffset);
  $(window).resize(updateOffset);

})(jQuery, Drupal, this, this.document);
