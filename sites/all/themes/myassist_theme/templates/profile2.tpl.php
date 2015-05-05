<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<?php if (!$page): ?>
  <h2<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h2>
<?php endif; ?>


  <?php
  $left_blocks = array("field_avatar","username","points","level");
  $right_blocks = array("achievements","userinfo","membersince","field_quote");
  ?>

  <div class="section">

    <div class="left">
        <?php
        foreach ($left_blocks as $blockname) {
          if (array_key_exists($blockname, $content)) {
            print render($content[$blockname]);
          }
        }
        ?>
    </div>

    <div class="right"<?php print $content_attributes; ?>>
      <?php
      foreach ($right_blocks as $blockname) {
        if (array_key_exists($blockname, $content)) {
          print render($content[$blockname]);
        }
      }
      ?>
    </div>

  </div>

  <div class="section">
    <?php
      foreach ($content as $blockname => $blockvalue) {
        if (!in_array($blockname, $left_blocks) && !in_array($blockname, $right_blocks)) {
          print render($blockvalue);
        }
      }
    ?>
  </div>
</div>
