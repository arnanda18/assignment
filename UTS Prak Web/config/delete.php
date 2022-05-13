<?php


    include "../db.php";


    $id = $_GET['id_biodata'];
    $images = $_GET['current_image'];
    $query = mysqli_query($conn, "DELETE FROM biodata WHERE id_biodata='$id'") or die(mysqli_error($conn));
    unlink('../images/'.$images);

    if ($query) {
       
        echo "<script>
            alert('Data telah dihapus');
            window.location.href = '../index.php';
        </script>
        ";
    }else{
        
        echo " <script>
            alert('Ada yang salah nihhh!');
            window.location.href = '../index.php';
        </script>
        ";
    }
?>