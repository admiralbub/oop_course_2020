<h1>Управление заказами</h1>

<!-- фильтр НАЧАЛО -->
<div style="text-align:center; padding:0 0 20px;">
	<form id="commentForm" name="commentForm" method="post" action="<?php echo general::link('orders/index') ; ?>">

		<div class="search_sort">
			<span class="search_sort_item">
				<label for="ordersSurname">Фамилия</label>
				<input type="text" name="ordersSurname" value="<?php echo isset($_SESSION['ordersSurname']) ? $_SESSION['ordersSurname'] : ''; ?>">
			</span>
			<span class="search_sort_item">
				<label for="ordersName">Имя</label>
				<input type="text" name="ordersName" value="<?php echo isset($_SESSION['ordersName']) ? $_SESSION['ordersName'] : ''; ?>">
			</span>
			<span class="search_sort_item">
				<label for="ordersCity">Город</label>
				<input type="text" name="ordersCity" value="<?php echo isset($_SESSION['ordersCity']) ? $_SESSION['ordersCity'] : ''; ?>">
			</span>
			<span class="search_sort_item">
				<label for="ordersPhone">Телефон</label>
				<input type="text" name="ordersPhone" value="<?php echo isset($_SESSION['ordersPhone']) ? $_SESSION['ordersPhone'] : ''; ?>">
			</span>
			<span class="search_sort_item">
				<label for="ordersEmail">E-Mail</label>
				<input type="text" name="ordersEmail" value="<?php echo isset($_SESSION['ordersEmail']) ? $_SESSION['ordersEmail'] : ''; ?>">
			</span>
			<span class="search_sort_item"><input type="submit" value="Найти"></span>
			
		</div>

		
		<div class="filter_sort">	
			<span class="search_sort_item">
				<label>Поиск по номеру заказа: </label><input type="text" name="id_orders" >
			</span>
			<span class="search_sort_item">
				<label>Дата заказа C </label><input type="text" name="date_s" id="datepicker" value="<?=(isset($_POST['date_s']) && $_POST['date_s'] != '') ? general::date_from_database($_POST['date_s']) : ''?>">
			</span>
			<span class="search_sort_item">
				<label>Дата заказа ПО </label><input type="text" name="date_po" id="datepicker1" value="<?=(isset($_POST['date_po']) && $_POST['date_po'] != '') ? general::date_from_database($_POST['date_po']) : ''?>">
			</span>
			<span class="search_sort_item"><input type="submit" value="Найти" name="send1"></span>
			
			<span class="search_sort_item"><input type="submit" value="Заказы за текущий месяц" name="send2"></span>
			<input type="hidden" name="date_s_hid" value="01.<?=date('m.Y')?>">
			<input type="hidden" name="date_po_hid" value="<?=date('t.m.Y')?>">
			
			<span class="search_sort_item">
				<input type="text" style="width: 40px;" id="sortFrom" />
				<label style="vertical-align: middle; margin-left: 5px;">-</label>
				<input type="text" style="width: 40px; margin-right: 5px;" id="sortTo" />
				<input type="button" value="Выгрузка в EXCEL" name="excel" id="excel">
				<span id="loader"></span>
			</span>
			
			<span class="item_last">				
				<label>Статус</label>
				<select name='status_orders' class="middle" id="status" onChange="commentForm.submit();">
					<option value="5" <?php echo $status_orders==5 ? 'selected' : ''; ?>>Все</option>
					<option value="3" <?php echo $status_orders==3 ? 'selected' : ''; ?>>Отменен</option>
					<option value="2" <?php echo $status_orders==2 ? 'selected' : ''; ?>>Отправлен</option>
                    <option value="4" <?php echo $status_orders==4 ? 'selected' : ''; ?>>К оплате</option>
					<option value="1" <?php echo $status_orders==1 ? 'selected' : ''; ?>>В работе</option>
					<option value="0" <?php echo $status_orders==0 ? 'selected' : ''; ?>>Новый</option>
				</select>
			</span>
		</div><!-- .search_sort--> 
		
	</form>
</div>
<!-- фильтр КОНЕЦ -->


<?php echo $msg ? $msg : '' ?>	
<span class="thisFilter"><?php echo $filter; ?></span>
<table class="table1" width="100%" border="0" cellspacing="0" cellpadding="0">
	<tr>
		<th></th>
		<th>№ заказа</th>
		<th>Дата заказа</th>
		<th>ФИО</th>
		<th>Телефон</th>
		<th>Перевозчик</th>
		<th>Область</th>
		<th>Город</th>
		<th>Сумма заказа</th>
		<th>Сумма отправки</th>
		<th>Статус заказа</th>
		<th>Дата проведения</th>
		<th>Операции</th>
		<th>Удаление</th>
	</tr>
	
<?$total = 0?>

<?php foreach ($result as $obj): ?>
<?php if($obj->phone == "") { ?>


<?php } else { ?>
	<?$us = registration::get_User_By_Id($obj->id_user)?>

	<?php $soSkidkoi = natalimomot::getSummaOrder($obj->id); ?>
	<tr data-id="<?=$obj->id?>" class="export">
		<td><input type="checkbox" value="<?php echo $obj->id; ?>" class="ids-export" /></td>
		<td><?php echo $obj->id; ?></td>
		<td style="min-width:120px;"><?php echo $obj->created_at ? date('d.m.Y H:i',strtotime($obj->created_at)) : '<span style="color:red;">Нет</span>'; ?></td>

		<td><?php if (!isset($obj->id_user)) { echo $obj->name.' '.$obj->father_name.' '.$obj->last_name; }else { echo general::link_to('users/new/id/'.$obj->id_user,$us->last_name.' '.$us->name.' '.$us->father_name.' ['.$us->id.']','target="_blank"'); }?></td>
		
		<td><?=$obj->phone?></td>
		<td style="text-align: center;">
			<?php if ($obj->deliver == 'Новая почта') { ?>
				<img src="/backend/img/nova.png" alt="" width="18px">
			<?php }elseif ($obj->deliver == 'Укрпочта') { ?>
				<img src="/backend/img/ukrposhta.png" width="14px" alt="">
			<?php } ?>
		</td>
		<td style="max-width:150px;">
			<?php if ($obj->id <= 24760):?>
				<?php echo $obj->region; ?>
			<?php endif; ?>
			<?php if ($obj->deliver == 'Новая почта') {
			  foreach ($regions as $key=>$value) {
				   if ($key == $obj->region) {
				       echo $value;
				   }
			    }
			 }
			 if ($obj->deliver == 'Укрпочта') {
					echo $obj->region;
			 }   
			?>
		</td>
		
		<td style="max-width:150px;">
			<?php if ($obj->id <= 24760):?>
				<?php echo $obj->city; ?>
			<?php endif; ?>
			<?php 
			    if ($obj->deliver == 'Новая почта') {
					foreach ($cities as $key=>$value) {
						if ($key == $obj->city) {
							echo $value->Description;
						}
						
					}
				}
				if ($obj->deliver == 'Укрпочта') {
					echo $obj->city;
				}
			?>
		</td>
		<td align="right" style="width:100px;"><?php echo number_format($soSkidkoi, 2, '.', ' '); ?></td>
		<td align="right" style="width:100px;">
                <?if($obj->status==4):?>
                    <?php echo number_format($obj->cost_order, 2, '.', ' '); ?>
                <?elseif($obj->status==2):?>
                    <?php echo number_format($obj->summa, 2, '.', ' '); ?>
                <?else:?>
                    <?php echo number_format(0, 2, '.', ' '); ?>
                <?endif?>
        </td>
		<td style="color:<?=$status_order_color[$obj->status]?>"><?php echo $status_order[$obj->status]; ?></td>		
		<td style="min-width:120px;"><?php echo $obj->updated_at ? date('d.m.Y H:i',strtotime($obj->updated_at)) : '<span style="color:red;">Нет</span>'; ?></td>
		<td><?php echo general::link_to('orders/new/id/'.$obj->id,'Редактировать'); ?></td>
		<td><?php echo general::link_to('orders/delete/id/'.$obj->id,'Удалить?','onclick="return confirm(\'Вы уверены?\')"'); ?></td>
	</tr>
	
	<?$total += $soSkidkoi?>
	<?$total2 += $obj->summa?>
<?php } ?>
<?php endforeach; ?>
	
	<tr>
		<th colspan="5">Итого по столбцу "Сумма заказа"<?php echo trim($filter) == '' ? ' (100 последних записей)' : '(Только отфильтрованные)'; ?></th>
		<th style="text-align:right;"><?php //echo number_format(natalimomot::getSummaOrders($filter), 2, '.', ' '); ?><?=number_format($total, 2, '.', ' ')?></th>
		<th style="text-align:right;"><?php //echo number_format(natalimomot::getSummaOrdersTrue($filter), 2, '.', ' '); ?><?=number_format($total2, 2, '.', ' ')?></th>
		<th colspan="4"></th>
	</tr>
	
</table>

<?php 
	echo $count>100 ? pager::pager_J(_APPLICATION."/".$tpl_folder."/index",100,$count,intval($_GET['page'])) : '';
?>

<script type="text/javascript">
	$('.thisFilter').hide();
	$(document).ready(function(){
		$('.checkbox_reset').click(function(){
			if ($(this).attr('checked')==true) {
			  $('#checkbox_all input').attr('checked',true);
			} else {
			  $('#checkbox_all input').attr('checked',false);
			}
		});
	  	<!-- календарь -->
		$.datepicker.setDefaults($.extend($.datepicker.regional["ru"]));
		$("#datepicker").datepicker();
		$("#datepicker1").datepicker();
		
		$('#excel').live('click', function(){
			
			var from = $('#sortFrom').val();
			var to	 = $('#sortTo').val();

			$('#loader').html('<img src="/backend/images/loader.gif" style="width: 22px; vertical-align: bottom;" />');
			$('#excel').hide();
			$.ajax({
				type: "POST",
				url: "<?php echo APPLICATION ?>/ajax/export_other.php",
				data: {'from':from,'to':to},
				dataType: 'JSON',
				success: 
					function(data){
						if (data.success) {
							$('#loader img').remove();
							$('#excel').show();
							window.location.href = "/tmp/export.xls?"+new Date();
						}
					}
			});
		});
		
	});
	</script>