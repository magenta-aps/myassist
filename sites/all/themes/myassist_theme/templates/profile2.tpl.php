<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<?php if (!$page): ?>
  <h2<?php print $title_attributes; ?>>
    <a href="<?php print $url; ?>"><?php print $title; ?></a>
  </h2>
<?php endif; ?>


  <?php
  $left_blocks = array("field_image","points","level","achievements");
  $right_blocks = array("username","field_gender","field_age","membersince","field_quote");
  ?>

  <aside class="left">
    <section class="region column sidebar region-sidebar-first">
      <?php
      foreach ($left_blocks as $blockname) {
        if (array_key_exists($blockname, $content)) {
          print render($content[$blockname]);
        }
      }
      ?>
    </section>
  </aside>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
    foreach ($right_blocks as $blockname) {
      if (array_key_exists($blockname, $content)) {
        print render($content[$blockname]);
      }
    }
    
    foreach ($content as $blockname => $blockvalue) {
      if (!in_array($blockname, $left_blocks) && !in_array($blockname, $right_blocks)) {
        print render($blockvalue);
      }
    }
    ?>
  </div>
</div>
