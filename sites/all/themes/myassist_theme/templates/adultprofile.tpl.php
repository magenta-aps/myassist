
<?php
$left_blocks = array("field_avatar");
$right_blocks = array("username","userinfo","field_biography");
$rendered_blocks = array();
?>

<div class="section">

  <div class="left">
    <?php
    foreach ($left_blocks as $blockname) {
      if (array_key_exists($blockname, $content) && !in_array($blockname, $rendered_blocks)) {
        print render($content[$blockname]);
        $rendered_blocks[] = $blockname;
      }
    }
    ?>
  </div>

  <div class="right"<?php print $content_attributes; ?>>
    <?php
    foreach ($right_blocks as $blockname) {
      if (array_key_exists($blockname, $content) && !in_array($blockname, $rendered_blocks)) {
        print render($content[$blockname]);
        $rendered_blocks[] = $blockname;
      }
    }
    ?>
  </div>

</div>