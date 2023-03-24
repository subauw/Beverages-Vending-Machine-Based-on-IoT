<?php
    class Nodemcu_log{

        // Connection
        private $conn;

        // Table
        private $db_table = "data_sensor";

        // Columns
        public $id;
        public $stok;
        public $waktu;

        // Db connection
        public function __construct($db){
            $this->conn = $db;
        }

        // CREATE
        public function createLogData(){
            $sqlQuery = "INSERT INTO
                        ". $this->db_table ."
                    SET
                        stok = :stok";
            $stmt = $this->conn->prepare($sqlQuery);
        
            // sanitize
            $this->stok=htmlspecialchars(strip_tags($this->stok));
        
            // bind data
            $stmt->bindParam(":stok", $this->stok);
            if($stmt->execute()){
               return true;
            }
            return false;
        }
    }
?>