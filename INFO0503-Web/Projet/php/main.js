
window.history.pushState("", "", '/index.php');

window.addEventListener("load", function () {
	onEnergyTypeUpdate();
	onQuantityUpdate();
});

function onEnergyTypeUpdate() {
	console.log("energyTypeUpdate()");
	let type = document.getElementById("energyType").value;
	let label = document.getElementById("quantityLabel");
	let labelMin = document.getElementById("minQuantityLabel");
	let labelMaxPrice = document.getElementById("maxPriceLabel");
	if (type == 0) {
		label.innerHTML = labelMin.innerHTML = "kWh";
		labelMaxPrice.innerHTML = "€/kWh";
	}
	else {
		label.innerHTML = labelMin.innerHTML = "L";
		labelMaxPrice.innerHTML = "€/L";
	}
}

var t = setTimeout(function(){}, 100);
function onQuantityUpdate() {
	console.log("quantityUpdate()");
	clearTimeout(t);
	t = setTimeout(updateQuantity, 1000);
}

function updateQuantity () {
	let quantity = document.getElementsByName("quantity")[0];
	let minQuantity = document.getElementsByName("minQuantity")[0];
	if (parseFloat(quantity.value) < parseFloat(minQuantity.value)) {
		console.log(quantity.value + " < " + minQuantity.value);
		quantity.value = minQuantity.value;
	}
}

