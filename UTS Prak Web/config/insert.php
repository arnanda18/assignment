<?php 
	include '../db.php';

	$name = $_POST['name'];
	$alamat = $_POST['alamat'];
	$agama = $_POST['agama'];
	$ttl = $_POST['ttl'];
	$pendidikan = $_POST['pendidikan'];
	$genre = $_POST['genre'];
	$prodi = $_POST['program_studi'];
	$hobbi = $_POST['hobbi'];
	$keahlian = $_POST['keahlian'];
	$pengalaman = $_POST['pengalaman'];
	$foto = $_FILES['pass_foto']['tmp_name'];

	$passFoto = uniqid().$name .".png";

	move_uploaded_file($foto, "../images/" .$passFoto);



	$db_insert = mysqli_query($conn, "INSERT INTO biodata (nama_lengkap, alamat, agama, tgl_lahir, pendidikan, jenis_kelamin, program_studi, hobbi, keahlian, pengalaman, pass_foto) VALUES ('$name', '$alamat', '$agama', '$ttl', '$pendidikan', '$genre', '$prodi', '$hobbi', '$keahlian', '$pengalaman', '$passFoto')");
	if ($db_insert) {  
	        echo "<script>
	            alert('Data berhasil ditambahkan');
	            window.location.href = '../index.php';
	        </script> ";

	    }else{
	        echo " <script>
	            alert('Data ada yang salah, coba cek lagi');
	            window.location.href = '../pages/insert.php';
	        </script> ";
	    }

 ?>
