<?php

/**
 * @file
 * Default taobaoke item list template file
 */
?>

<?php foreach ($taobaoke_items as $taobaoke_item): ?>

<div class="taobaoke_item_box">

  <div class="taobaoke_item">

    <div class="pic">
      <a target="_blank" href="<?php print $taobaoke_item['url']; ?>">
        <img src="<?php print $taobaoke_item['pic_url']; ?>">
      </a>
    </div>

    <h3 class="title"><?php print $taobaoke_item['link'] ?></h3>

    <div class="attribute">
      <div class="price">
        <span class="symbol">￥</span>
        <span><em class="money"><?php print $taobaoke_item['price']; ?></em></span>
      </div>
      <div class="place">
        <?php print $taobaoke_item['item_location']; ?>
      </div>
    </div>

  </div>

</div>
<?php endforeach; ?>