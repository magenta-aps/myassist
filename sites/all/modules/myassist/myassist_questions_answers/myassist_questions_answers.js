(function($) {
    Drupal.behaviors.answersSort = {
        attach : function(context, settings) {
            var form = $("#views-exposed-form-question-answers-default");
            form.find("input[type=submit]").hide();
            setTimeout(function () { // Execute after other scripts, or the view won't be found
                var dropdown = form.find(".views-widget-sort-by select").get(0);
                if (dropdown && !dropdown.exposedFormAjax) {
                    var container = form.parents(".view-id-question_answers");
                    var className = container.attr("className") || "";
                    var classNames = className.split(" ");
                    var domId;
                    for (var i = 0; i < classNames.length; i++) {
                        var m = /^view-dom-id-([0-9a-f]+)$/.exec(classNames[i]);
                        if (m) {
                            domId = m[1];
                            break;
                        }
                    }
                    if (domId) {
                        var view = Drupal.views.instances['views_dom_id:' + domId];
                        if (view && view.element_settings) {
                            var element_settings = $.extend({}, view.element_settings);
                            element_settings.event = "change";
                            dropdown.exposedFormAjax = new Drupal.ajax($(dropdown).attr('id'), dropdown, element_settings);
                        }
                    }
                }
            }, 10);
        }
    };
}(jQuery));
