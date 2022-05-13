<?php 
	include '../db.php';

	$idBiodata = $_POST['id_biodata'];
	$name = $_POST['name'];
	$alamat = $_POST['alamat'];
	$agama = $_POST['agama'];
	$ttl = $_POST['ttl'];
	$pendidikan = $_POST['pendidikan'];
	$genre = $_POST['genre'];
	$prodi = $_POST['prodi'];
	$hobbi = $_POST['hobbi'];
	$keahlian = $_POST['keahlian'];
	$pengalaman = $_POST['pengalaman'];
	$foto = $_FILES['pass_foto']['tmp_name'];

	$passFoto = $_POST['current_image'];

	move_uploaded_file($foto, "../images/" .$passFoto);


	$db_update = mysqli_query($conn, "UPDATE biodata SET nama_lengkap = '$name', alamat = '$alamat', agama = '$agama', tgl_lahir = '$ttl', pendidikan = '$pendidikan', jenis_kelamin ='$genre', program_studi = '$prodi', hobbi = '$hobbi', keahlian = '$keahlian', pengalaman = '$pengalaman', pass_foto = '$passFoto' WHERE id_biodata = '$idBiodata'");
	if ($db_update) {  
	        echo "<script>
	            alert('Data berhasil diupdate');
	            window.location.href = '../index.php';
	        </script> ";

	    }else{
	        echo " <script>
	            alert('Data ada yang salah, coba cek lagi');
	            window.location.href = '../pages/update.php';
	        </script> ";
	    }

 ?>