<?php
/**
 * @file
 * addfullajax-page.tpl.php
 *
 * Available variables:
 *   all that for page.tpl.php
 *   +
 *   $regions = array that contain regions that need render (look at configuration)
 *   $main_region = string, region name that contain main contant (look at configuration)
 *   $content_id = CSS id of main block content(look at configuration)
 */
?>
<?php foreach ($regions as $region) : ?>
  <?php if ($region == $main_region): // render main content ?>
    <!-- :ax:<?php print $content_id; ?>:begin: //-->
    <?php print render($title_prefix); ?>
    <?php if ($title): ?><h1 class="title" id="page-title"><?php print $title; ?></h1><?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
    <?php print render($variables['page'][$region]); ?>
    <?php print $feed_icons; ?>
    <!-- :ax:<?php print $content_id; ?>:end: //-->
  <?php else : // render additional blocks ?>
    <!-- :ax:flax-<?php print $region; ?>:begin: //-->
    <?php print render($variables['page'][$region]); ?>
    <!-- :ax:flax-<?php print $region; ?>:end: //-->
  <?php endif;?>
<?php endforeach; ?>