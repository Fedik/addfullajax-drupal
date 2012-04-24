<?php
krumo($variables);
/**
 * @file
 * addfullajax-page.tpl.php
 *
 * Available variables:
 *   all that for page.tpl.php
 *   +
 *   $regions = array that contain regions that need render
 *   $main_region = string, region name that contain main contant
 */

foreach ($regions as $region) {
  print '<!-- :ax:flax-' . $region . ':begin: //-->';
  print render($variables['page'][$region]);
  print '<!-- :ax:flax-' . $region . ':end: //-->';
}
