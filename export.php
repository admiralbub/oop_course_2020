<?php
    error_reporting(E_ALL & ~E_NOTICE & ~E_DEPRECATED);
	
    include '../../main.php';

	//$arr = $_POST['arr'];
	//$arr = implode(',', $arr);
	$filter = str_replace('\\','',htmlspecialchars_decode(trim(strip_tags($_POST['filter']))));
	$res = mysql::query("SELECT 
							order_number.*,
							users.last_name,
							users.name AS first_name,
							users.father_name AS father_name,
							users.city AS u_city
						FROM order_number
						LEFT JOIN users ON order_number.id_user = users.id
						WHERE order_number.id > 0 ".$filter."
						ORDER BY order_number.id DESC");

	if(!$res)
		return;
		
	include_once HOST.'/backend/plagin/excel_new/Classes/PHPExcel.php';
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
	
	$aSheet->getStyle('A')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('B')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('C')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('D')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('E')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('F')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('G')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	$aSheet->getStyle('H')->getAlignment()->setHorizontal(PHPExcel_Style_Alignment::HORIZONTAL_CENTER);
	
	$aSheet->getStyle('A1')->getFont()->setBold(true);
	$aSheet->getStyle('B1')->getFont()->setBold(true);
	$aSheet->getStyle('C1')->getFont()->setBold(true);
	$aSheet->getStyle('D1')->getFont()->setBold(true);
	$aSheet->getStyle('E1')->getFont()->setBold(true);
	$aSheet->getStyle('F1')->getFont()->setBold(true);
	$aSheet->getStyle('G1')->getFont()->setBold(true);
	$aSheet->getStyle('H1')->getFont()->setBold(true);
	
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
	
	$aSheet->setCellValue('A1','№ заказа');
	$aSheet->setCellValue('B1','Дата заказа');
	$aSheet->setCellValue('C1','Фамилия, имя');
	$aSheet->setCellValue('D1','E-Mail');
	$aSheet->setCellValue('E1','Телефон');
	$aSheet->setCellValue('F1','Город');
	$aSheet->setCellValue('G1','Сумма заказа');
	$aSheet->setCellValue('H1','Сумма отправки');
	
	$aSheet->getStyle('G')->getNumberFormat()->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_NUMBER);
	$aSheet->getStyle('H')->getNumberFormat()->setFormatCode(PHPExcel_Style_NumberFormat::FORMAT_NUMBER);
	
	$row = 2;
	
	foreach($res as $obj)
	{
		$email = mysql::query_one("SELECT email FROM users WHERE id=".$obj->id_user)->email;
		$cost = mysql::query("SELECT * FROM orders WHERE number_order=".$obj->id);
		
		$total = 0;
		foreach($cost AS $c)
		{
			$total += $c->cost*$c->kolvo;
		}
		//$total = number_format(basket::get_summa_so_skidkoi($total), 2, '.', ' ');
		$total = basket::get_summa_so_skidkoi($total);
		
		$aSheet->setCellValue('A'.$row,$obj->id);
		$aSheet->setCellValue('B'.$row,general::date_from_database($obj->created_at));
		$aSheet->setCellValue('C'.$row,$obj->last_name.' '.$obj->first_name.' '.$obj->father_name);
		$aSheet->setCellValue('D'.$row,$email);
		$aSheet->setCellValue('E'.$row,$obj->phone);
		//$aSheet->setCellValue('F'.$row,str_replace('&quot;', '"', $obj->address));
		$aSheet->setCellValue('F'.$row,$obj->u_city);
		$aSheet->setCellValue('G'.$row,$total);
		$aSheet->setCellValue('H'.$row,$obj->summa);
		$row++;
    }
	
	include(HOST."/backend/plagin/excel_new/Classes/PHPExcel/Writer/Excel5.php");
	$objWriter = new PHPExcel_Writer_Excel5($pExcel);
	header('Content-Type: application/vnd.ms-excel; charset=utf-8');
	header('Content-Disposition: attachment;filename="export.xls"');
	header('Cache-Control: max-age=0');
	$objWriter->save(HOST.'/tmp/export.xls');
?>