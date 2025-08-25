package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

public class Emperor extends Edo_Society implements SupremeGovernance {
	
	private String dynasty;
	private String imperialHouse;
	private static Emperor emperor = new Emperor();
		
	private Xogum xogum;
	
	private Emperor() {};

	@Override
	public boolean politicalAction(String action) {
		return xogum.politicalAction(action);
	}

	public String getDynasty() {
		return dynasty;
	}

	public void setDynasty(String dynasty) {
		this.dynasty = dynasty;
	}

	public String getImperialHouse() {
		return imperialHouse;
	}

	public void setImperialHouse(String imperialHouse) {
		this.imperialHouse = imperialHouse;
	}

	public static Emperor getEmperor() {
		return emperor;
	}

	public Xogum getXogum() {
		return xogum;
	}

	public void setXogum(Xogum xogum) {
		this.xogum = xogum;
	}


}
