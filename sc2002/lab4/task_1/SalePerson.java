class SalePerson implements Comparable<SalePerson> {
	private String firstName;
	private String lastName;
	private int totalSales;

	public SalePerson(String firstName, String lastName, int totalSales) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.totalSales = totalSales;
	}


	@Override
	public String toString() {
		return String.format("%s, %s : %d", getLastName(), getFirstName(), getTotalSales());
	}

	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof SalePerson)) {
			return false;
		}

		SalePerson other = (SalePerson) obj;
		return (getFirstName().equals(other.getFirstName()) &&
				getLastName().equals(other.getLastName()));

	}
	@Override
	public int compareTo(SalePerson o) {
		if (getTotalSales() > o.getTotalSales()) {
			return 1;
		}
		if (getTotalSales() < o.getTotalSales()) {
			return -1;
		}
		// rank in ascending order of last names
		return -getLastName().compareTo(o.getLastName());
	}

	public String getFirstName() {
		return firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public int getTotalSales() {
		return totalSales;
	}
}
