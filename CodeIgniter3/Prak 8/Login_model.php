<?php
	/**
	 * 
	 */
	class Login_model extends CI_Model
	{

		public $username;
		public $name;
		public $pass;
		
		public function __construct()
		{
			// code...
			parent::__construct();

			$this->load->database();
		}

		public function login_check($username, $password) {

			$condition = "username=" . "'" . $username . "' AND " . "password=" . "'" . $password . "'";
			$this->db->select('*');
			$this->db->from('user');
			$this->db->where($condition);
			$this->db->limit(1);
			$query = $this->db->get();

			if ($query->num_rows() == 1) {
				return true;
			} else {
				return false;
			}
		}

		public function user_information($username){

			$condition = "username =" . "'" . $username . "'";
			$this->db->select('*');
			$this->db->from('user');
			$this->db->where($condition);
			$this->db->limit(1);
			$query = $this->db->get();

			if ($query->num_rows() == 1) {

				return $query->result();

				} else {

				return false;
			}
		}
	}
?>
