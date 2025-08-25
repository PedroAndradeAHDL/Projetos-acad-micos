package br.edu.unifei.ecot12.finalproject.xogunatotokugawa;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public abstract class Edo_Society {
	
	private static String politicalDomination = "Xogunato Tokugawa";
	private static String governance = "Sakoku";
	private String name;
	private String politicalReputation;
	
	private Calendar birth;
	private Calendar death;
	private boolean politicalInfluecne;
	private boolean socialInfluence;
	
	private Religion religion;
	
	private List<Untouchable> untouchables = new ArrayList<Untouchable>();
	
	public String getPoliticalDomination() {
		return politicalDomination;
	}

	public String getGovernance() {
		return governance;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getPoliticalReputation() {
		return politicalReputation;
	}

	public void setPoliticalReputation(String politicalReputation) {
		this.politicalReputation = politicalReputation;
	}

	public Calendar getBirth() {
		return birth;
	}

	public void setBirth(Calendar birth) {
		this.birth = birth;
	}

	public Calendar getDeath() {
		return death;
	}

	public void setDeath(Calendar death) {
		this.death = death;
	}

	public boolean isPoliticalInfluecne() {
		return politicalInfluecne;
	}

	public void setPoliticalInfluecne(boolean politicalInfluecne) {
		this.politicalInfluecne = politicalInfluecne;
	}

	public boolean isSocialInfluence() {
		return socialInfluence;
	}

	public void setSocialInfluence(boolean socialInfluence) {
		this.socialInfluence = socialInfluence;
	}

	public Religion getReligion() {
		return religion;
	}

	public List<Untouchable> getUntouchables() {
		return untouchables;
	}

	public void addUntouchables(Untouchable untouchables) {
		this.untouchables.add(untouchables);
	}
	
	public void removeUntouchables(Untouchable untouchables) {
		this.untouchables.remove(untouchables);
	}

	public void setUntouchables(List<Untouchable> untouchables) {
		this.untouchables = untouchables;
	}

	public void setReligion(Religion religion) {
		this.religion = religion;
	}
	
	

}
