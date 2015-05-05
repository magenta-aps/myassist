
<?php
$left_blocks = array("field_avatar","username","points","level");
$right_blocks = array("achievements","userinfo","membersince","field_quote");
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

<?php
if (array_key_exists("nodes", $content) && !in_array("nodes", $rendered_blocks)) {
  ?>
  <div class="section nodes">
    <h3>Aktiviteter</h3>
    <?php
    print render($content["nodes"]);
    ?>
  </div>
  <?php
}
/*foreach ($content as $blockname => $blockvalue) {
  if (!in_array($blockname, $rendered_blocks)) {
    print render($blockvalue);
    $rendered_blocks[] = $blockname;
  }
}*/
?>