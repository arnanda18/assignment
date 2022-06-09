<?php
	class Hello extends CI_Controller
	{ 
		public function index() {
			$this->load->model('Hello_model');
			$model = $this->Hello_model;
			$s = $model->string;
			$data = ['text'=>$s];
			$data['stringNIM'] = '191110227';
			$data['stringNama'] = 'Arnanda Nuryasa';
			$data['stringMsg'] = 'Ini adalah kodingan versi saya menggunakan CodeIniter 3. Sederhana sih, ngikut modul saja'; 
			$this->load->view('hello_view', $data, ['text' =>$s]);
			
		}
}
?>
