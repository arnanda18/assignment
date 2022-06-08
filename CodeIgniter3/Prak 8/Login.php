<?php 
	
	/**
	 * 
	 */
	class Login extends CI_Controller
	{
		
		public $model=NULL;


		public function __construct()
		{
			// Constructor
			parent::__construct();

			//Load Model
			$this->load->model('Login_model');
			$this->model=$this->Login_model;

			//Load Session
			$this->load->library('session');

			//Load Validation Library
			$this->load->library('form_validation');

			//Load Helper
			$this->load->helper('url');
			$this->load->helper('html');
			$this->load->helper('form');

		}

		

		public function index() {
	
			$this->form_validation->set_rules('username', 'Username', 'trim|required|xss_clean');
			$this->form_validation->set_rules('password', 'Password', 'trim|xss_clean');

			if ($this->form_validation->run() == FALSE) {

				if (isset($this->session->userdata['logged_in'])) {
	                $this->load->view('login_success_view');
	            } else {
	                $this->load->view('login_form_view');
	            }
			}else{
				$username = $this->input->post('username');
				$password = $this->input->post('password');
				

				$result = $this->Login_model->login_check($username, $password);
				if($result == TRUE){

					//$this->session->set_userdata('logged_in',$this->model->username);

					$username = $this->input->post('username');
					$result =$this->Login_model->user_information($username);

					if ($result !=false) {
						// Ambil data user
						$session_data = array(
							'username' => $result[0]->username,
							'full_name' => $result[0]->full_name,
							'email' => $result[0]->email,
							'role' => $result[0]->role,
						);

						$this->session->set_userdata('logged_in', $session_data);
						$this->load->view('login_success_view');

					}

				} else {	
					$data = array(
						'error_message' => 'Invalid Username or Password!'
					);
					$this->load->view('login_form_view', $data);				
				}
			}
		}

		public function logout(){
			$this->session->unset_userdata('logged_in');
			session_destroy();
			redirect('login');
			
		}
	}

?>
