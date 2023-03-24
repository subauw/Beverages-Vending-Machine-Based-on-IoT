<?php
    header("Access-Control-Allow-Origin: *");
    header("Content-Type: application/json; charset=UTF-8");

    include_once '../config/database.php';
    include_once '../class/nodemcu_log.php';

    $database = new Database();
    $db = $database->getConnection();

    $item = new Nodemcu_log($db);
	
	if ($_SERVER['REQUEST_METHOD'] === 'POST') {
		$data = json_decode(file_get_contents("php://input"));
		$item->stok = $data->stok;
	} 
    elseif ($_SERVER['REQUEST_METHOD'] === 'GET'){
		$item->stok = isset($_GET['stok']) ? $_GET['stok'] : die('Data Error!');
	}else {
		die('wrong request method');
	}
	
    if($item->createLogData()){
        echo 'Data created successfully.';
    } else{
        echo 'Data could not be created.';
    }
?>