<?php
    error_reporting(E_ALL & ~E_NOTICE & ~E_DEPRECATED);
	
    include '../../main.php';
	//$arr = $_POST['arr'];
	//$arr = implode(',', $arr);
	$filter = str_replace('\\','',htmlspecialchars_decode(trim(strip_tags($_POST['filter']))));
	/*$res = mysql::query("SELECT 
							order_number.*,
						FROM order_number
						WHERE order_number.id > 0 ".$filter."
						ORDER BY order_number.id DESC");*/
	$from = intval($_POST['from']);
	$to   = intval($_POST['to']);
	
	if($from > 0 AND $to > 0) {
		if($from > $to) {
			$limit = ' LIMIT '.$to.', '.($from - $to + 1);
		} else {
			$limit = ' LIMIT '.$from.', '.($to - $from + 1);
		}
	} else if($from > 0 AND $to == 0) {
		$limit = ' LIMIT '.$from.', 1000000';
	} else if($to > 0 AND $from == 0) {
		$limit = ' LIMIT 1, '.$to;
	} else {
		$limit = '';
	}
	$sort = ptashka::sort_backend();
	$res = mysql::query("SELECT 
							order_number.*,
							users.last_name,
							users.name AS first_name,
							users.city AS u_city,
							regions.name AS region_name
						FROM order_number
						LEFT JOIN users ON order_number.id_user = users.id
						LEFT OUTER JOIN regions ON order_number.region = regions.id
						WHERE order_number.status =2
						ORDER BY order_number.".$sort.$limit, 0);
	

	if(!$res) {
		die(json_encode(array('success' => 0)));
	}
		
	include_once HOST.'/backend/plagin/excel_new/Classes/PHPExcel.php';
	
	$cities = novaposhta::getCitiesJSON();
	$regions = novaposhta::getRegionsJSON();
	
	$pExcel = new PHPExcel();
		
	$pExcel->setActiveSheetIndex(0);

	$aSheet = $pExcel->getActiveSheet();
	$aSheet->setTitle('Список заказов');
		
	$aSheet->getColumnDimension('A')->setAutoSize(true);
	$aSheet->getColumnDimension('B')->setAutoSize(true);
	$aSheet->getColumnDimension('C')->setAutoSize(true);
	$aSheet->getColumnDimension('D')->setAutoSize(true);
	$aSheet->getColumnDimension('E')->setAutoSize(true);
	$aSheet->getColumnDimension('F')->setAutoSize(true);
	$aSheet->getColumnDimension('G')->setAutoSize(true);
	$aSheet->getColumnDimension('H')->setAutoSize(true);
	$aSheet->getColumnDimension('I')->setAutoSize(true);
	
	$aSheet->getStyle('A')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('B')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('C')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('D')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('E')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('F')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('G')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('H')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('I')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	
	$aSheet->getStyle('A1')->getFont()->setBold(true);
	$aSheet->getStyle('B1')->getFont()->setBold(true);
	$aSheet->getStyle('C1')->getFont()->setBold(true);
	$aSheet->getStyle('D1')->getFont()->setBold(true);
	$aSheet->getStyle('E1')->getFont()->setBold(true);
	$aSheet->getStyle('F1')->getFont()->setBold(true);
	$aSheet->getStyle('G1')->getFont()->setBold(true);
	$aSheet->getStyle('H1')->getFont()->setBold(true);
	$aSheet->getStyle('I1')->getFont()->setBold(true);
	
	$aSheet->getStyle('A1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('A1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('B1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('B1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('C1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('C1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('D1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('D1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('E1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('E1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('F1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('F1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('G1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('G1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('H1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('H1')->getFill()->getStartColor()->setRGB('EEEEEE');
	$aSheet->getStyle('I1')->getFill()->setFillType(PHPExcel_Style_Fill::FILL_SOLID);
	$aSheet->getStyle('I1')->getFill()->getStartColor()->setRGB('EEEEEE');
	
	$aSheet->setCellValue('A1','№ заказа');
	$aSheet->setCellValue('B1','Дата заказа');
	$aSheet->setCellValue('C1','Фамилия, имя');
	$aSheet->setCellValue('D1','E-Mail');
	$aSheet->setCellValue('E1','Телефон');
	$aSheet->setCellValue('F1','Область');
	$aSheet->setCellValue('G1','Город');
	$aSheet->setCellValue('H1','Сумма заказа');
	$aSheet->setCellValue('I1','Сумма отправки');
	
	$aSheet->getStyle('H')->getNumberFormat()->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_NUMBER);
	$aSheet->getStyle('I')->getNumberFormat()->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_NUMBER);
	
	$row = 2;
	//$amount = 0;
	/*
	foreach($res as $obj)
	{
		
		
		$total = 0;
		
		
		$aSheet->setCellValue('A'.$row,$obj->id);
		$aSheet->setCellValue('B'.$row,general::date_from_database($obj->created_at));
		if ($obj->id<=2768) {
			$aSheet->setCellValue('C'.$row,$obj->last_name.' '.$obj->first_name);
			$aSheet->setCellValue('F'.$row,$obj->region_name);
			$aSheet->setCellValue('G'.$row,$obj->u_city);
		} else {
			$aSheet->setCellValue('C'.$row,$obj->last_name.' '.$obj->first_name);
			if($obj->deliver == 'Новая почта') {		
				foreach ($regions as $key=>$value) {
					if ($key == $obj->region) {
						$region=$value;
					}
				}	
			}elseif($obj->deliver == 'Укрпочта') {	
				 $district = ukrposhta::getDistrictukr($obj->region);
				 $json = json_decode($district, true);
				 $lest = count($json['Entries']['Entry']);
		 		    
			     $region= $json['Entries']['Entry']['0']['REGION_UA'];
			}
			$aSheet->setCellValue('F'.$row,$region);		
			
			if ($obj->deliver == 'Новая почта') {
				foreach ($cities as $key=>$value) {
					if ($key == $obj->city) {
						$city=$value->Description;
					}
					
				}
			}elseif($obj->deliver == 'Укрпочта') {	
				 $district = ukrposhta::getStreetukr($obj->city);
				 $json = json_decode($district, true);
				 $lest = count($json['Entries']['Entry']);
		 		    
			     $city = $json['Entries']['Entry']['0']['CITY_UA'];
			}  else {
				$city=$obj->city;
			}
			$aSheet->setCellValue('G'.$row,$city);
		}

		//$aSheet->setCellValue('D'.$row,$email);
		$aSheet->setCellValue('E'.$row,$obj->phone);
		


		$aSheet->setCellValue('H'.$row,$total);
		
		if($obj->status==4){
			$this_cost_order = $obj->deliv_order;
		}elseif($obj->status==2){
		   $this_cost_order = $obj->cost_order;
		}else{
		   $this_cost_order = 0;
		}
		
		$aSheet->setCellValue('I'.$row,$this_cost_order);
		//$row++;
		$row++;

	}*/
	//$cost = ptashka::cost_excel();
	
	foreach($res as $obj)
	{
		
		//$total = number_format(basket::get_summa_so_skidkoi($total), 2, '.', ' ');

		
		$total = 0;
		$email = mysql::query_one("SELECT email FROM users WHERE id=".$obj->id_user)->email;
		
		foreach($cost AS $c):
			if($c->number_order == $obj->id) {
				$total += $c->cost*$c->kolvo;
			}
		endforeach;


		$aSheet->setCellValue('D'.$row,$email);
		$aSheet->setCellValue('A'.$row,$obj->id);
		$aSheet->setCellValue('B'.$row,general::date_from_database($obj->created_at));
	//	$aSheet->setCellValue('C'.$row,$obj->name);
		if (registration::get_User_By_Id($obj->id_user)->last_name) {
					$user=registration::get_User_By_Id($obj->id_user)->last_name.' '.registration::get_User_By_Id($obj->id_user)->name.' '.registration::get_User_By_Id($obj->id_user)->middle_name.' ['.registration::get_User_By_Id($obj->id_user)->id.']'; 
				} else {
					$user=registration::get_User_By_Id($obj->id_user)->name.' ['.registration::get_User_By_Id($obj->id_user)->id.']';
				}
		$aSheet->setCellValue('C'.$row,$user);
		if ($obj->id<=24760) {
			$aSheet->setCellValue('C'.$row,$obj->last_name.' '.$obj->first_name);
			$aSheet->setCellValue('F'.$row,$obj->region_name);
			$aSheet->setCellValue('G'.$row,$obj->u_city);
		} else {
			//$aSheet->setCellValue('C'.$row,$obj->last_name.' '.$obj->first_name);
			if($obj->deliver == 'Новая почта') {		
				foreach ($regions as $key=>$value) {
					if ($key == $obj->region) {
						$region=$value;
					}
				}	
			}
			$aSheet->setCellValue('F'.$row,$region);		
			
			if ($obj->deliver == 'Новая почта') {
				foreach ($cities as $key=>$value) {
					if ($key == $obj->city) {
						$city=$value->Description;
					}
					
				}
			}
			$aSheet->setCellValue('G'.$row,$city);
		}
		$aSheet->setCellValue('E'.$row,$obj->phone);
		
		
		$aSheet->setCellValue('H'.$row,$obj->summa);
		$aSheet->setCellValue('I'.$row,$obj->summa);
		
		$row++;
	}
	
	
	include(HOST."/backend/plagin/excel_new/Classes/PHPExcel/Writer/Excel5.php");
	$objWriter = new PHPExcel_Writer_Excel5($pExcel);
	//header('Content-Type: application/vnd.ms-excel; charset=utf-8');
	//header('Content-Disposition: attachment;filename="export.xls"');
	//header('Cache-Control: max-age=0');
	$objWriter->save(HOST.'/tmp/export.xls');
	die(json_encode(array('success' => 1)));
?>