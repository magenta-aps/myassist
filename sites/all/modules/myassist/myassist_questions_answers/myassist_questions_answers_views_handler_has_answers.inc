<?php

/**
 * A handler for achievement titles.
 *
 */
class myassist_questions_answers_views_handler_has_answers extends views_handler_field {

  function render($empty = FALSE) {
    $total = isset($this->view->total_rows) ? $this->view->total_rows : count($this->view->result);

    switch ($total) {
      case 0:
        return t("no");
      default:
        return t("yes");
    }
  }
}
