$( document ).ready(onLoad);

function moveButton(target) {
	target.style.marginTop = parseInt(target.style.marginTop)-5+'px';
	
}

function onLoad() {
	//var dataK = document.getElementById('dataKeeper');
	
	
	/*dataK.onmouseover = function() {
		dataK.style.color = 'red';
	};*/
	
	<!-- используя существующую функцию -->

	function dataK_mouseout() {
		$(this).css("color",'black');
	}

	//dataK.onmouseout = dataK_mouseout;
	
	$('#dataKeeper').hover( 
		function() {
			$(this).css("color", "red");
		}, 
		dataK_mouseout
	);
	

	
}

