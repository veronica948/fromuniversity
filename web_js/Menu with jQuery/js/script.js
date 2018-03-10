$(document).ready(onLoad);

function onLoad2(){
  $("#dataKeeper").click(function() {
			$(this).css("background-color","violet"),
			$(this).css("color","white")
		});
}

function onLoad() {
  list1 = {
	  name: "Main",
	  submenu: []
  };
  list2 = {
	  name: "list2",
	  submenu: ["l1","l2","l3"]
  };
  list3 = {
	  name: "list3",
	  submenu: ["l1","l2"]
  };
  list4 = {
	  name: "list4",
	  submenu: ["l1","l2"]
  }; 
  var mas=[list1,list2,list3,list4];
  
  $('#menu').append('<ul id=main_menu></ul>');
  
  for(var i=0;i<mas.length;i++)
  {
	//alert(1);
	  $("#main_menu").append('<li id=title><a href='+mas[i].name+'.html>'+mas[i].name+'</a></li>');
	  $("#main_menu>li:last-child").append('<ul id=submenu></ul>');
	  for(var j=0;j<mas[i].submenu.length;j++) {
		$("#main_menu>li:last-child #submenu").append('<li><a href='+mas[i].name+'_'+mas[i].submenu[j]+'.html>'+mas[i].submenu[j]+'</a></li>');
	  }
   }
   
	onLoad2();
	
	$("#main_menu #title").mouseover(Show);
	$("#main_menu #title").mouseout(Hide);
	
	function Show(){
		$(this.lastChild).css("display","block");
	};

	function Hide() {
		$(this.lastChild).css("display","none");
	}
	
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