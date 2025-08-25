package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

import java.util.Calendar;

public abstract class Social_Policy {
	
	private String objective;
	private Calendar startPeriod;
	private Calendar endPeriod;	
	private String shogunatoName;
	private boolean foreigTrade;
	
	private Religion christianity = new Christianity();
	private Religion buddhism = new Buddhism();
	private Religion shintoism = new Shintoism();
	
	public abstract void toggleChristianity();
	public abstract void toggleBuddhism();
	public abstract void toggleShintoism();

	public String getObjective() {
		return objective;
	}

	public void setObjective(String objective) {
		this.objective = objective;
	}

	public Calendar getStartPeriod() {
		return startPeriod;
	}

	public void setStartPeriod(Calendar startPeriod) {
		this.startPeriod = startPeriod;
	}

	public Calendar getEndPeriod() {
		return endPeriod;
	}

	public void setEndPeriod(Calendar endPeriod) {
		this.endPeriod = endPeriod;
	}

	public String getShogunatoName() {
		return shogunatoName;
	}

	public void setShogunatoName(String shogunatoName) {
		this.shogunatoName = shogunatoName;
	}

	public boolean isForeigTrade() {
		return foreigTrade;
	}

	public void setForeigTrade(boolean foreigTrade) {
		this.foreigTrade = foreigTrade;
	}

	public Religion getChristianity() {
		return christianity;
	}

	public void setChristianity(Religion christianity) {
		this.christianity = christianity;
	}

	public Religion getBuddhism() {
		return buddhism;
	}

	public void setBuddhism(Religion buddhism) {
		this.buddhism = buddhism;
	}

	public Religion getShintoism() {
		return shintoism;
	}

	public void setShintoism(Religion shintoism) {
		this.shintoism = shintoism;
	};
	

}
