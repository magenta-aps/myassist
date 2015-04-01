<?php

/**
 * @file
 * Definition of views_handler_area_result.
 */

/**
 * Views area handler to display answers count.
 *
 * @ingroup views_area_handlers
 */
class views_handler_answers_count extends views_handler_area {
  /**
   * Find out the information to render.
   */
  function render($empty = FALSE) {
    $output = '';
    $count = count($this->view->result);
    $total = isset($this->view->total_rows) ? $this->view->total_rows : count($this->view->result);

    switch ($total) {
      case 0:
        return t("No answers yet.");

      case 1:
        return t("1 answer");

      default:
        return $total . " " . t("answers");

    }
  }
}
