$(document).ready(onLoad);
function onLoad2(){
  $("#dataKeeper").click(function() {
			$(this).css("background-color","violet"),
			$(this).css("color","white")
		});
}
function onLoad(){
	$("#menu a").bind("click",function() {
				 loadPage($(this).attr("href"));
				 return false;
			});
	function loadPage(page) {
	  $.ajax({
		  // the URL for the request
		  url: page,
	   
		  // the data to send (will be converted to a query string)
		  //data: {
	  //        id: 123
	  //    },
	   
		  // whether this is a POST or GET request
		  type: "GET",
	   
		  // the type of data we expect back
		  //dataType : "json",
	   
		  // code to run if the request succeeds;
		  // the response is passed to the function
		  success: function( html ) {
			  $("#content").html( html );
			  onLoad2();
		  },
	   
		  // code to run if the request fails; the raw request and
		  // status codes are passed to the function
		  error: function( xhr, status ) {
			  console.log( "Sorry, there was a problem!" );
		  },
	   
		  // code to run regardless of success or failure
		  complete: function( xhr, status ) {
			  console.log( "The request is complete!" );
		  }
	  });
	  }
}